/*							-*- coding: utf-8 -*-
 *
 * redir.c	-- Redirection fichiers
 *
 * Erick Gallesio (2012-03-09)
 * Stéphane Lavirotte (2017/03/23)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void usage(char *progname)
{
    fprintf(stderr, "Usage: %s direction file cmd arg ...\n", progname);
    fprintf(stderr, "       direction = R or W\n");
    exit(1);
}

int main(int argc, char *argv[])
{
    int new_fd, std_fd, mode;

    if (argc < 4) {
        usage(*argv);
    }

    /* Vérifier que le premier argument est bien un R ou un W */
    switch (argv[1][0]) {
    case 'R':
    case 'r':
        std_fd = 0;
        break;
    case 'W':
    case 'w':
        std_fd = 1;
        break;
    default:
        usage(*argv);
    }

    /* Faire la redirection */
    mode = (std_fd == 0) ? O_RDONLY : (O_WRONLY | O_TRUNC | O_CREAT);
    if ((new_fd = open(argv[2], mode, 0600)) < 0) {
        perror(*argv);
        exit(1);
    }

    close(std_fd);
    dup(new_fd);

    /* Execute la commande passée en paramètre */
    execvp(argv[3], argv + 3);
    return 1; /* pour le compilateur, car ne doit pas arriver */
}