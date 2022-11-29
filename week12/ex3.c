#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define EV_PRESSED 1
#define EV_RELEASED 0
#define EV_REPEAT 2
#define Key_Max 224

int pressed[KEY_MAX];

int no_pressed()
{
    int number_of_pressed = 0;
    for (int i = 0; i < KEY_MAX; i++)
    {
        if (pressed[i] > 0)
        {
            number_of_pressed++;
        }
    }
    return number_of_pressed;
}

int main(int argc, char *argv[])
{
    FILE* output = fopen("ex3.txt", "a");
    if (output == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    struct input_event ev;
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    if (fd == -1)
    {
        perror("Cannot open file /dev/input/by-path/platform-i8042-serio-0-event-kbd");
        exit(EXIT_FAILURE);
    }

    // Print all the shortcuts
    printf("Shortcuts:\n");
    printf("P+E gives 'I passed the Exam!'\n");
    printf("C+A+P gives 'Get some cappuccino!'\n");
    printf("G+C gives 'Get some coffee!'\n");
    
    fprintf(output, "Shortcuts:\n");
    fprintf(output, "P+E gives 'I passed the Exam!'\n");
    fprintf(output, "C+A+P gives 'Get some cappuccino!'\n");
    fprintf(output, "G+C gives 'Get some coffee!'\n");

    while (read(fd, &ev, sizeof(ev)))
    {
        pressed[ev.code] = ev.value;

        if (pressed[KEY_E] > 0 && pressed[KEY_P] > 0 && no_pressed() == 3)
        {
            printf("I passed the Exam!\n");
            fprintf(output, "I passed the Exam!\n");
        }

        if (pressed[KEY_C] > 0 && pressed[KEY_A] > 0 && pressed[KEY_P] && no_pressed() == 4)
        {
            printf("Get some cappuccino!\n");
            fprintf(output, "Get some cappuccino!\n");
        }

        if (pressed[KEY_G] > 0 && pressed[KEY_C] > 0 && no_pressed() == 3)
        {
            printf("Get some coffee!\n");
            fprintf(output, "Get some coffee!\n");
        }
    }

    close(fd);
    fclose(output);
    return 0;
}
