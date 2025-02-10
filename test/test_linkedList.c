#include <unity.h>
#include <stdlib.h>
#include <time.h>

#include "../linkedList.h"

LinkedListNode *list;

void setUp(void)
{
    list = NULL;
}

void tearDown(void)
{
    if (list)
    {
        freeLinkedList(&list);
    }
}

void redirect_stdout_to_buffer(char *buffer, size_t size, FILE **original_stdout, FILE **stream)
{
    *stream = fmemopen(buffer, size, "w");
    if (*stream == NULL)
    {
        TEST_FAIL_MESSAGE("Failed to open buffer stream");
    }

    // Save the original stdout
    *original_stdout = stdout;
    stdout = *stream;
}

void restore_stdout(FILE *original_stdout, FILE *stream)
{
    fflush(stream);
    stdout = original_stdout;
    fclose(stream);
}

void test_createLinkedListNode(void)
{
    for (int i = 0; i < 1000; i++)
    {
        LinkedListNode *node = createLinkedListNode(i);
        TEST_ASSERT_NOT_NULL(node);
        TEST_ASSERT_EQUAL(i, node->data);
        free(node);
    }
}

void test_createLinkedList_random(void)
{
    srand((unsigned int)time(NULL));
    int nodes[5];
    for (int i = 0; i < 5; i++)
    {
        nodes[i] = rand() % 100; // Random numbers between 0 and 99
    }

    list = createLinkedList(nodes, 5);
    TEST_ASSERT_NOT_NULL(list);
    LinkedListNode *current = list->next;

    // sort the nodes
    qsort(nodes, 5, sizeof(int), compare);

    for (int i = 0; i < 5; i++)
    {
        TEST_ASSERT_EQUAL(nodes[i], current->data);
        current = current->next;
    }
    freeLinkedList(&list);
}

void test_createLinkedList_random_large(void)
{
    srand((unsigned int)time(NULL));
    int nodes[1000];
    for (int i = 0; i < 1000; i++)
    {
        nodes[i] = rand() % 1000; // Random numbers between 0 and 999
    }

    list = createLinkedList(nodes, 1000);
    TEST_ASSERT_NOT_NULL(list);
    LinkedListNode *current = list->next;

    qsort(nodes, 1000, sizeof(int), compare);

    for (int i = 0; i < 1000; i++)
    {
        TEST_ASSERT_EQUAL(nodes[i], current->data);
        current = current->next;
    }
    freeLinkedList(&list);
}

void test_createLinkedList(void)
{
    int nodes[] = {1, 2, 3, 4, 5};
    list = createLinkedList(nodes, 5);
    TEST_ASSERT_NOT_NULL(list);
    LinkedListNode *current = list->next;
    for (int i = 0; i < 5; i++)
    {
        TEST_ASSERT_EQUAL(nodes[i], current->data);
        current = current->next;
    }
    freeLinkedList(&list);
}

void test_insertLinkedListNode(void)
{
    list = createLinkedList(NULL, 0);
    for (int i = 0; i < 1000; i++)
    {
        insertLinkedListNode(list, i);
    }

    LinkedListNode *current = list->next;
    for (int i = 0; i < 1000; i++)
    {
        TEST_ASSERT_EQUAL(i, current->data);
        current = current->next;
    }
    freeLinkedList(&list);
}

void test_insertLinkedListNode_reversed(void)
{
    list = createLinkedList(NULL, 0);

    for (int i = 4; i >= 0; i--)
    {
        insertLinkedListNode(list, i);
    }

    LinkedListNode *current = list->next;
    for (int i = 0; i < 5; i++)
    {
        TEST_ASSERT_EQUAL(i, current->data);
        current = current->next;
    }
    freeLinkedList(&list);
}

void test_insertLinkedListNode_random(void)
{
    list = createLinkedList(NULL, 0);
    srand((unsigned int)time(NULL));
    int nodes[1000];

    for (int i = 0; i < 1000; i++)
    {
        nodes[i] = rand() % 1000; // Random numbers between 0 and 999
        insertLinkedListNode(list, nodes[i]);
    }

    LinkedListNode *current = list->next;

    qsort(nodes, 1000, sizeof(int), compare);

    for (int i = 0; i < 1000; i++)
    {
        TEST_ASSERT_EQUAL(nodes[i], current->data);
        current = current->next;
    }

    freeLinkedList(&list);
}

void test_printLinkedList(void)
{
    int nodes[] = {1, 2, 3, 4, 5};
    list = createLinkedList(nodes, 5);

    // Redirect stdout to a buffer
    char buffer[1024];
    FILE *original_stdout;
    FILE *stream;

    redirect_stdout_to_buffer(buffer, sizeof(buffer), &original_stdout, &stream);

    printLinkedList(list);
    freeLinkedList(&list);

    restore_stdout(original_stdout, stream);

    TEST_ASSERT_EQUAL_STRING("List: 1 2 3 4 5 \n", buffer);
}

void test_printLinkedList_random(void)
{
    srand((unsigned int)time(NULL));
    int nodes[1000];
    for (int i = 0; i < 1000; i++)
    {
        nodes[i] = rand() % 1000; // Random numbers between 0 and 999
    }

    list = createLinkedList(nodes, 1000);
    TEST_ASSERT_NOT_NULL(list);

    // Sort the nodes
    qsort(nodes, 1000, sizeof(int), compare);

    // Redirect stdout to a buffer
    char buffer[4096];
    FILE *original_stdout;
    FILE *stream;

    redirect_stdout_to_buffer(buffer, sizeof(buffer), &original_stdout, &stream);

    printLinkedList(list);
    freeLinkedList(&list);

    restore_stdout(original_stdout, stream);

    // Create the expected string
    char expected[8912];
    int offset = snprintf(expected, sizeof(expected), "List: ");
    for (int i = 0; i < 1000; i++)
    {
        offset += snprintf(expected + offset, sizeof(expected) - (unsigned int)offset, "%d ", nodes[i]);
    }
    snprintf(expected + offset, sizeof(expected) - (unsigned int)offset, "\n");

    TEST_ASSERT_EQUAL_STRING(expected, buffer);
}

void test_freeLinkedList(void)
{
    list = createLinkedList(NULL, 0);
    for (int i = 0; i < 1000; i++)
    {
        insertLinkedListNode(list, i);
    }
    freeLinkedList(&list);
    TEST_ASSERT_NULL(list);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_createLinkedListNode);
    RUN_TEST(test_createLinkedList);
    RUN_TEST(test_insertLinkedListNode_reversed);
    RUN_TEST(test_createLinkedList_random);
    RUN_TEST(test_createLinkedList_random_large);
    RUN_TEST(test_insertLinkedListNode);
    RUN_TEST(test_insertLinkedListNode_random);
    RUN_TEST(test_printLinkedList);
    RUN_TEST(test_printLinkedList_random);
    RUN_TEST(test_freeLinkedList);
    return UNITY_END();
}
