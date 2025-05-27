#ifndef KOTA_ORANG_H
#define KOTA_ORANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 50

typedef struct NodeOrang {
    char namaOrang[MAX_STR];
    struct NodeOrang *nextOrang;
} NodeOrang;

typedef struct NodeKota {
    char namaKota[MAX_STR];
    NodeOrang *headOrang;
    struct NodeKota *nextKota;
} NodeKota;

enum { FALSE = 0, TRUE = 1 };
extern NodeKota *headKota;

void initKota(void);

// Operasi Kota
void tambahKota(const char *namaKota);
int hapusKota(const char *namaKota);
NodeKota* cariKota(const char *namaKota);

// Operasi Orang
void tambahOrang(const char *namaKota, const char *namaOrang);
int hapusOrang(const char *namaKota, const char *namaOrang);
NodeOrang* cariOrang(NodeKota *k, const char *namaOrang);

void tampilkanSemua(void);
void tampilkanPerKota(const char *namaKota);

// Utility internal
static void insertLastOrang(NodeOrang **head, const char *namaOrang);
static void deleteAllOrang(NodeOrang *head);

#endif 