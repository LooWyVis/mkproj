#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void create_c_project(const char *project_name, int init_git) {
    printf("Création d'un projet C : %s\n", project_name);
    mkdir(project_name, 0755);
    chdir(project_name);
    
    FILE *main_c = fopen("main.c", "w");
    if (main_c) {
        fprintf(main_c, "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\\n\");\n    return 0;\n}\n");
        fclose(main_c);
    }

    FILE *makefile = fopen("Makefile", "w");
    if (makefile) {
        fprintf(makefile, "CC=gcc\nCFLAGS=-Wall\n\nall:\n\t$(CC) main.c -o main $(CFLAGS)\n");
        fclose(makefile);
    }

    if (init_git) {
        system("git init");
    }
}

void create_python_project(const char *project_name, int init_git) {
    printf("Création d'un projet Python : %s\n", project_name);
    mkdir(project_name, 0755);
    chdir(project_name);

    FILE *main_py = fopen("main.py", "w");
    if (main_py) {
        fprintf(main_py, "print(\"Hello, world!\")\n");
        fclose(main_py);
    }

    if (init_git) {
        system("git init");
    }
}

void create_html_project(const char *project_name, int init_git) {
    printf("Création d'un projet Web : %s\n", project_name);
    mkdir(project_name, 0755);
    chdir(project_name);
    
    mkdir("css", 0755);
    mkdir("js", 0755);

    FILE *index_html = fopen("index.html", "w");
    if (index_html) {
        fprintf(index_html, "<!DOCTYPE html>\n<html>\n<head>\n<title>%s</title>\n<link rel=\"stylesheet\" href=\"css/style.css\">\n</head>\n<body>\n<h1>Bienvenue sur %s</h1>\n</body>\n</html>", project_name, project_name);
        fclose(index_html);
    }

    FILE *style_css = fopen("css/style.css", "w");
    if (style_css) {
        fprintf(style_css, "body { font-family: Arial, sans-serif; }");
        fclose(style_css);
    }

    if (init_git) {
        system("git init");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage : mkproj [type] [nom_du_projet] [--git]\n");
        printf("Types disponibles : c, python, html\n");
        return 1;
    }

    char *type = argv[1];
    char *project_name = argv[2];
    int init_git = (argc == 4 && strcmp(argv[3], "--git") == 0);

    if (strcmp(type, "c") == 0) {
        create_c_project(project_name, init_git);
    } else if (strcmp(type, "python") == 0) {
        create_python_project(project_name, init_git);
    } else if (strcmp(type, "html") == 0) {
        create_html_project(project_name, init_git);
    } else {
        printf("Erreur : Type de projet inconnu. Utilisez c, python ou html.\n");
        return 1;
    }

    printf("Projet %s créé avec succès !\n", project_name);
    return 0;
}
