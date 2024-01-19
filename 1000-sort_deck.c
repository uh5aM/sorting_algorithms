#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - Compare two cards for qsort
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Negative value if a < b, 0 if a == b, positive value if a > b
 */
static int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = ((const deck_node_t *)a)->card;
    const card_t *card_b = ((const deck_node_t *)b)->card;

    if (card_a->kind != card_b->kind)
        return (card_a->kind - card_b->kind);
    return (strcmp(card_a->value, card_b->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t count = 0;
    deck_node_t *current = *deck;

    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    while (current)
    {
        count++;
        current = current->next;
    }

    qsort(*deck, count, sizeof(deck_node_t), compare_cards);
}
