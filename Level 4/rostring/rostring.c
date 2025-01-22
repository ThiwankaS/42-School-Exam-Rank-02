#include <unistd.h>

int write_word(char *line, int index)
{
    int count = 0;

    char *start = line + index;

    while (*start && *start != ' ' && *start != '\t')
    {
        write(1, start, 1);
        start++;
        count++;
    }

    return count;
}

int main(int argc, char **argv)
{
    char *str;
    int index = 0;
    int first_word_stat;

    if (argc == 2)
    {
        str = argv[1];

        while (str[index] == ' ' || str[index] == '\t')
            index++;
            
        first_word_stat = index;
        
        while (str[index] && str[index] != ' ' && str[index] != '\t')
                index++;

        while (str[index])
        {
            int written = write_word(str, index);

            index += written;

            while (str[index] == ' ' || str[index] == '\t')
                index++;

            write(1, " ", 1);
        }
        write_word(argv[1], first_word_stat);
    }

    write(1, "\n", 1);
    return 0;
}
