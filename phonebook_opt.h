#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16


/* opt version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_INFO *pInfo;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __PHONE_BOOK_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];

} info;

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);

/* optimal versoin 2*/
typedef unsigned int hashIndex;
typedef struct __PHONE_BOOK_HASH_TABLE {
    unsigned int tableSize;  /* the size of the table */
    entry **list;  /* the table elements */
} hashTable;

hashTable *createHashTable(int tableSize);
entry* findNameHash(char *key, hashTable *ht);
int appendHash(char *key, hashTable *ht);
hashIndex hash1(char *key, hashTable *ht);
hashIndex hash2(char *key, hashTable *ht);

#endif
