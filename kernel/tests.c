#include <basic.h>
#include <assert.h>
#include <snx/cpu.h>
#include <snx/irq.h>
#include <snx/pmm.h>
#include <snx/spalloc.h>
#include <snx/tests.h>
#include <snx/thread.h>
#include <snx/timer.h>
#include <x86/pic.h>

void run_sync_tests(void);

void motd_kernel_thread(void *arg) {
    printf("Message Of The Day\n");
    const char *message = arg;
    printf("The message is '%s'!\n", message);
    kthread_exit();
}

void lots_of_threads(void *message) {
    printf("%s", message);
    kthread_exit();
}

noreturn void test_sleepy_thread(void *_) {
    while (true) {
        printf("sleepy thread");
        sleep_thread(seconds(1));
    }
}

void print_key(interrupt_frame *frame, void *_x) {
    char scancode = inb(0x80);
    printf("keyboard interrupt: %c\n", scancode);
}

void run_spalloc_test() {
    struct testing {
        int a, b, c, d, e, f, g, h;
    };
    struct spalloc foobar;
    sp_init(&foobar, struct testing);

    struct testing *first = sp_alloc(&foobar);
    assert(first == foobar.region);
    first->a = 10;

    struct testing *second = sp_alloc(&foobar);
    assert(second == sp_at(&foobar, 1));
    second->a = 11;

    assert(first->a == 10);

    first->g = 1;
    sp_free(&foobar, first);
    assert(first->g != 1); // poison
    assert(second->a == 11);

    struct testing *re_first = sp_alloc(&foobar);
    assert(re_first == first);

    assert(foobar.capacity == 0x10000);
    assert(foobar.count == 2);
}

static unsigned long int next = 1;
 
int randn( int max ) // RAND_MAX assumed to be 32767
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % (max+1);
}
 
void srand( unsigned int seed )
{
    next = seed;
}

char* get_motd(int init_time) {
    srand(init_time);
    int random = randn(5);
    switch (random)
    {
    case 0:
        return "This is a motd";
        break;
    case 1:
        return "Someone is speaking well of you, How unusual!";
        break;
    case 2:
        return "The cow is nothing but a machine which makes grass suitable for us people to eat.";
        break;
    case 3:
        return "The Fifth Rule: You have taken yourself too seriously.";
        break;
    case 4:
        return "Never make any misteaks";
        break;
    
    default:
        return "/dev/rtw 0-0";
        break;
    }
}

void run_all_tests(int init_time) {
    run_sync_tests();
    run_spalloc_test();
    kthread_create(motd_kernel_thread, get_motd(init_time));
    // kthread_create(test_sleepy_thread, NULL);

    for (int i = 0; i < 50; i++) {
        kthread_create(lots_of_threads, "");
        kthread_create(lots_of_threads, "");
    }

    pic_irq_unmask(IRQ_KEYBOARD);
    irq_install(IRQ_KEYBOARD, print_key, NULL);
}
