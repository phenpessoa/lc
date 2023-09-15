#include <stdlib.h>
#include <stdbool.h>
#include "ihm.h"

IntHashMap *IHM_new()
{
    IntHashMap *m = (IntHashMap *)malloc(sizeof(IntHashMap));
    if (!m)
        return NULL;

    m->len = 0;
    m->cap = INITIAL_CAPACITY;
    m->table = (IHM_Item **)malloc(sizeof(IHM_Item *) * INITIAL_CAPACITY);
    if (!m->table)
    {
        free(m);
        return NULL;
    }

    for (int i = 0; i < INITIAL_CAPACITY; i++)
    {
        m->table[i] = NULL;
    }

    return m;
}

bool IHM_set(IntHashMap *m, int key, int value)
{
    if ((double)m->len / m->cap > LOAD_FACTOR_THRESHOLD)
    {
        if (!resize(m))
            return false;
    }

    int idx = hash(key, m->cap);
    IHM_Item *newItem = (IHM_Item *)malloc(sizeof(IHM_Item));
    if (!newItem)
        return false;

    newItem->key = key;
    newItem->value = value;
    newItem->next = m->table[idx];
    m->table[idx] = newItem;
    ++m->len;
    return true;
}

int *IHM_get(IntHashMap *m, int key)
{
    int idx = hash(key, m->cap);
    IHM_Item *cur = m->table[idx];
    while (cur != NULL)
    {
        if (cur->key == key)
        {
            return &cur->value;
        }
        cur = cur->next;
    }
    return NULL;
}

void IHM_delete(IntHashMap *m, int key)
{
    int idx = hash(key, m->cap);
    IHM_Item *cur = m->table[idx];
    IHM_Item *prev = NULL;

    while (cur != NULL)
    {
        if (cur->key == key)
        {
            if (prev == NULL)
            {
                m->table[idx] = cur->next;
            }
            else
            {
                prev->next = cur->next;
            }
            free(cur);
            --m->len;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void IHM_free(IntHashMap *m)
{
    for (int i = 0; i < m->cap; ++i)
    {
        IHM_Item *cur = m->table[i];
        while (cur != NULL)
        {
            IHM_Item *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(m->table);
    free(m);
}

static int hash(int key, int capacity)
{
    return key % capacity;
}

static bool resize(IntHashMap *m)
{
    int newCapacity = GROW_BY * m->cap;
    IHM_Item **new_table = (IHM_Item **)malloc(sizeof(IHM_Item *) * newCapacity);
    if (!new_table)
        return false;

    for (int i = 0; i < newCapacity; ++i)
    {
        new_table[i] = NULL;
    }

    for (int i = 0; i < m->cap; ++i)
    {
        IHM_Item *cur = m->table[i];
        if (!cur)
            continue;
        int newIdx = hash(cur->key, newCapacity);
        while (cur != NULL)
        {
            IHM_Item *next = cur->next;
            int newIdx = hash(cur->key, newCapacity);
            cur->next = new_table[newIdx];
            new_table[newIdx] = cur;
            cur = next;
        }
    }

    free(m->table);
    m->table = new_table;
    m->cap = newCapacity;
    return true;
}