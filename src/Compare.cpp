#include "../inc/Compare.h"

/**
 * @brief Returns result of compearing of two strings ПЕРЕДЕЛАТЬ
 * \param [in] text Array of strings
 */

int MyStrcmp (const char * str_one, const char * str_two)
{
    assert (str_one != NULL);
    assert (str_two != NULL);

    printf ("%s\n%s\n", str_one, str_two);

    int char_counter_one = HowManyNotLetters (str_one, STRAIGHT);
    int char_counter_two = HowManyNotLetters (str_two, STRAIGHT);

    while (str_one[char_counter_one] != '\0')
    {
        if (str_one[char_counter_one] == str_two[char_counter_two])
        {
            char_counter_one++;
            char_counter_two++;
            printf ("Im stupid \n");
        }
        else
            return (str_one[char_counter_one] - str_two[char_counter_two]);
    }

    return (str_one[char_counter_one] - str_two[char_counter_two]);
}

int MyStrcmpFromBack (const char * str_one, const char * str_two)
{
    assert (str_one != NULL);
    assert (str_two != NULL);

    int not_letters_in_one = HowManyNotLetters (str_one, REVERS);
    int not_letters_in_two = HowManyNotLetters (str_two, REVERS);

    printf ("%d %d\n", not_letters_in_one, not_letters_in_two);

    int len_str_one = strlen (str_one) - not_letters_in_one - 1;
    int len_str_two = strlen (str_two) - not_letters_in_two - 1;

    printf ("%s\n%s\n", str_one, str_two);
    
    if (len_str_one < len_str_two)
    {
        for (;len_str_one >= 0;)
        {
            if (str_one[len_str_one] == str_two[len_str_two])
                continue;
            else
                return (str_one[len_str_one] - str_two[len_str_two]);
             len_str_one--; 
             len_str_two--;
        }
    }
    else
    {
        for (;len_str_two >= 0;)
        {
            if (str_one[len_str_one] == str_two[len_str_two])
            {
                len_str_two--;
                len_str_one--;
            }
            else
                return (str_one[len_str_one] - str_two[len_str_two]);
        }
    }

    return 0;
}   

int HowManyNotLetters (const char * str, int arg)
{
    int not_letters = 0;

    if (arg == STRAIGHT)
        while (int charc = tolower (str[not_letters]) < 97 && charc > 122)
        {
            not_letters++;
            printf ("Im stupid\n");

        }
    else
    {   
        int str_len = strlen (str) - 1;

        while (int charc = tolower (str[str_len]) < 97 || charc > 122)
            {
                not_letters++;
                str_len--;
                printf ("Im stupid \n");
            }
    }
    return not_letters;
}