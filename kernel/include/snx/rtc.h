#pragma once
#ifndef SNX_RTC_H
#define SNX_RTC_H

#include <x86/cpu.h>
#include <snx/syscall.h>

#define CURRENT_YEAR 2021

int centuryreg = 0x00;

unsigned char second;
unsigned char minute;
unsigned char hour;
unsigned char day;
unsigned char month;
unsigned int year;

enum {
    cmos = 0x70,
    cmos_data = 0x71
};

int getupdateflag() {
    outb(cmos, 0x0A);
    return (inb(cmos_data) & 0x80);
}

unsigned char getrtcregister(int reg) {
    outb(cmos, reg);
    return inb(cmos_data);
}

void updatertc() {
    unsigned char century;
    unsigned char last_second;
    unsigned char last_minute;
    unsigned char last_hour;
    unsigned char last_day;
    unsigned char last_month;
    unsigned char last_year;
    unsigned char last_century;
    unsigned char registerb;

    while(getupdateflag());
    second = getrtcregister(0x00);
    minute = getrtcregister(0x01);
    hour = getrtcregister(0x04);
    day = getrtcregister(0x07);
    month = getrtcregister(0x08);
    year = getrtcregister(0x09);
    if(centuryreg != 0) {
        century = getrtcregister(centuryreg);
    }

    do {
        last_second = second;
        last_minute = minute;
        last_hour = hour;
        last_day = day;
        last_month = month;
        last_year = year;
        last_century = century;

        while(getupdateflag());
        second = getrtcregister(0x00);
        minute = getrtcregister(0x01);
        hour = getrtcregister(0x04);
        day = getrtcregister(0x07);
        month = getrtcregister(0x08);
        year = getrtcregister(0x09);
        if(centuryreg != 0) {
            century = getrtcregister(centuryreg);
        }
    } while( (last_second != second) || (last_minute != minute) || (last_hour != hour) ||
             (last_day != day) || (last_month != month) || (last_year != year) || 
             (last_century != century) );
    
    registerb = getrtcregister(0x0B);

    if(!(registerb & 0x04)) {
        second = (second & 0x0F) + ((second / 16) * 10);
        minute = (minute & 0x0F) + ((minute / 16) * 10);
        hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
        day = (day & 0x0F) + ((day / 16) * 10);
        month = (month & 0x0F) + ((month / 16) * 10);
        year = (year & 0x0F) + ((year / 16) * 10);
        if(centuryreg != 0) {
            century = (century & 0x0F) + ((century / 16) * 10);
        }
    }

    if(!(registerb & 0x02) && (hour & 0x80)) {
        hour = ((hour & 0x7F) + 12) % 24;
    }

    if(centuryreg != 0) {
        year += century * 100;
    } else {
        year += (CURRENT_YEAR / 100) * 100;
        if(year < CURRENT_YEAR) year += 100;
    }
}

sysret sys_get_year() {
    updatertc();
    return year;
}

sysret sys_get_month() {
    updatertc();
    return month;
}

sysret sys_get_day() {
    updatertc();
    return day;
}

sysret sys_get_hour() {
    updatertc();
    return hour;
}

sysret sys_get_minute() {
    updatertc();
    return minute;
}

sysret sys_get_second() {
    updatertc();
    return second;
}

#endif