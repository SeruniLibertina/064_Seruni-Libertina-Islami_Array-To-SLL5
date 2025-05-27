#include "kota.h"

NodeKota *headKota = NULL;

void initKota(void) {
    headKota = NULL;
}

NodeKota* cariKota(const char *namaKota) {
    NodeKota *p = headKota;
    while (p) {
        if (strcmp(p->namaKota, namaKota) == 0)
            return p;
        p = p->nextKota;
    }
    return NULL;
}

void tambahKota(const char *namaKota) {
    if (cariKota(namaKota)) {
        printf("Kota '%s' sudah ada.\n", namaKota);
        return;
    }
    NodeKota *baru = malloc(sizeof(NodeKota));
    strcpy(baru->namaKota, namaKota);
    baru->headOrang = NULL;
    baru->nextKota = NULL;
    if (!headKota) {
        headKota = baru;
    } else {
        NodeKota *t = headKota;
        while (t->nextKota)
            t = t->nextKota;
        t->nextKota = baru;
    }
}

int hapusKota(const char *namaKota) {
    NodeKota *p = headKota;
    NodeKota *prev = NULL;
    while (p && strcmp(p->namaKota, namaKota) != 0) {
        prev = p;
        p = p->nextKota;
    }
    if (!p) return FALSE;
    // Hapus semua Orang di kota itu
    deleteAllOrang(p->headOrang);
    // Lepas node Kota
    if (!prev) {
        headKota = p->nextKota;
    } else {
        prev->nextKota = p->nextKota;
    }
    free(p);
    return TRUE;
}

static void insertLastOrang(NodeOrang **head, const char *namaOrang) {
    NodeOrang *baru = malloc(sizeof(NodeOrang));
    strcpy(baru->namaOrang, namaOrang);
    baru->nextOrang = NULL;
    if (!*head) {
        *head = baru;
    } else {
        NodeOrang *t = *head;
        while (t->nextOrang)
            t = t->nextOrang;
        t->nextOrang = baru;
    }
}

void tambahOrang(const char *namaKota, const char *namaOrang) {
    NodeKota *k = cariKota(namaKota);
    if (!k) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }
    insertLastOrang(&k->headOrang, namaOrang);
}

NodeOrang* cariOrang(NodeKota *k, const char *namaOrang) {
    NodeOrang *p = k->headOrang;
    while (p) {
        if (strcmp(p->namaOrang, namaOrang) == 0)
            return p;
        p = p->nextOrang;
    }
    return NULL;
}

int hapusOrang(const char *namaKota, const char *namaOrang) {
    NodeKota *k = cariKota(namaKota);
    if (!k) return FALSE;
    NodeOrang *p = k->headOrang;
    NodeOrang *prev = NULL;
    while (p && strcmp(p->namaOrang, namaOrang) != 0) {
        prev = p;
        p = p->nextOrang;
    }
    if (!p) return FALSE;
    if (!prev) {
        k->headOrang = p->nextOrang;
    } else {
        prev->nextOrang = p->nextOrang;
    }
    free(p);
    return TRUE;
}

static void deleteAllOrang(NodeOrang *head) {
    NodeOrang *p = head;
    while (p) {
        NodeOrang *nxt = p->nextOrang;
        free(p);
        p = nxt;
    }
}

void tampilkanSemua(void) {
    NodeKota *k = headKota;
    while (k) {
        printf("\nKota: %s\n", k->namaKota);
        NodeOrang *o = k->headOrang;
        while (o) {
            printf(" - %s\n", o->namaOrang);
            o = o->nextOrang;
        }
        k = k->nextKota;
    }
}

void tampilkanPerKota(const char *namaKota) {
    NodeKota *k = cariKota(namaKota);
    if (!k) {
        printf("Kota '%s' tidak ditemukan.\n", namaKota);
        return;
    }
    printf("\nKota: %s\n", k->namaKota);
    NodeOrang *o = k->headOrang;
    while (o) {
        printf(" - %s\n", o->namaOrang);
        o = o->nextOrang;
    }
}
