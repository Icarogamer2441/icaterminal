#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    
    int running = 1;
    
    printf("@@@@@@@@@@@@@@@@@&&&&&G55555555555555G&&&&&@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@&&&#55555J??????????????J55555#&&&@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@&#5YYY??????????????????????????YYY5#&@@@@@@@@@@@\n");
    printf("@@@@@@@@@&#5J???????YGY?5GGGGGGP?????YGY???????J5B#@@@@@@@@@\n");
    printf("@@@@@@@#BJ!?????????P@G?B@GPPPP5???YBGPGBY???????J5B#@@@@@@@\n");
    printf("@@@@@#GJ~^:7????????5@G?B@Y????????P@&B&@5?????????J5G#@@@@@\n");
    printf("@@@&P5J!:^:7????????P@G?B@5JJJJJ?Y&GJYYYJB&J??????????5P&@@@\n");
    printf("@@&#5Y?!:^:7????????5&P?G&#####B?Y&G?????B&J??????????Y5#&@@\n");
    printf("@&P5???!:::7???????????????JJJJ?????????????????????????5P&@\n");
    printf("@&P5???!:~~7?7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?????5P&@\n");
    printf("BBYJ???!:7???^::::::::::::::::::::::::::::::::::::~?????JYBB\n");
    printf("55?????!:!???5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5???????55\n");
    printf("55??????7????&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B???????55\n");
    printf("55???????????&@@#~7&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P^~~^^^^YP\n");
    printf("PY^^^~777????&@@@&G~JB#@@@@@@@@@@@@@@@@@@@@@@@@@@@B7??~^^^YP\n");
    printf("PY~~~~~~~7???&@@@@&PJ~P@@@@@@@@@@@@@@@@@@@@@@@@@@@B???????55\n");
    printf("55???????????&@@&5J!5@BYYYYYY5@@@@@@@@@@@@@@@@@@@@B???????55\n");
    printf("BBYJ?????????&@@&?5@@@G??????J&@@@@@@@@@@@@@@@@@@@B?????JYBB\n");
    printf("@&P5?????????&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B?????5P&@\n");
    printf("@&P5?????????YYYYYYYYYYYYYYYYYYYYYYYYYYY5?7Y5YYYY5Y?????5P&@\n");
    printf("@@&#5Y???????????????????????????????????^:7??????????Y5#&@@\n");
    printf("@@@&P5???????????????????????????????????~:^^?????????5P&@@@\n");
    printf("@@@@@#G5J????????????????????????????????~::^??????J5G#@@@@@\n");
    printf("@@@@@@@#B5J??????????????????????????????~:^^????J5B#@@@@@@@\n");
    printf("@@@@@@@@@#B5J????????????????????????????~::^??J5B#@@@@@@@@@\n");
    printf("@@@@@@@@@@@&#5YYY????????????????????????~:?JY5#&@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@&&&#55555J??????????????J555YY#&&&@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@&&&&&G55555555555555G&&&&&@@@@@@@@@@@@@@@@@\n");
    
    char username[100];
    printf("what's your name?: ");
    scanf("%s", username);
    int limite;
    printf("what's the limit of the storage you want?: ");
    scanf("%d", &limite);
    char additional[100];
    printf("do you want to add aditional things? [y/n]: ");
    scanf("%s", additional);
    
    if(limite > 100000){
        printf("you cant use more than 100.000 of memory, beacuse of this, the game will re-use 100.000 of memory");
        limite = 100000;
    }
    
    arq = fopen("memory.txt", "a");
    
    if (arq == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    if(strcmp(additional,"y") == 0){
        fprintf(arq,"loaded all commands\n");
        fprintf(arq,"loaded all functions for the commands\n");
        fprintf(arq,"you gonna lose some memory, but you can reset this memory to dont lose more (you gonna lose 218 of memory)");
        fprintf(arq,"use 'recommend' command to see all recomended things");
        printf("added additional things! (dont use again if you start the terminal again)");
    } else {
        printf("okay, now you can use with 0 of space used!");
    }
    
    fseek(arq, 0, SEEK_END);
    long tamanhoAtual = ftell(arq);
    fseek(arq, 0, SEEK_SET);
    
    while(running){
        if(tamanhoAtual <= limite){
            char command[100];
            printf("\n%s > ", username);
            scanf("%s", command);
            
            if(strcmp(command, "version") == 0){
                printf("icaterminal v1.6\n");
            }
            if(strcmp(command, "exit") == 0){
                running = 0;
            }
            if(strcmp(command, "write-on-memory") == 0){
                char content[200];
                scanf("%s\n", content);
                fprintf(arq, "\n%s", content);
                
                fseek(arq, 0, SEEK_END);
                long tamanhoAtual = ftell(arq);
                fseek(arq, 0, SEEK_SET);
            }
            if(strcmp(command, "help") == 0){
                printf("write-on-memory\n");
                printf("exit\n");
                printf("version\n");
                printf("open\n");
                printf("clear\n");
                printf("link\n");
                printf("createfile\n");
                printf("main.py\n");
                printf("main.rb\n");
                printf("reset\n");
                printf("resetclose\n");
                printf("create-react-app\n");
                printf("recommend\n");
                printf("main.js\n");
                printf("print\n");
                printf("app\n");
		        printf("main.c\n");
                printf("logo\n");
            }
            if(strcmp(command, "open") == 0){
                char url[200];
                #ifdef _WIN32
                    const char *comando = "start %s";
                #elif __linux__
                    const char *comando = "xdg-open %s";
                #else
                    // Adicione suporte para outros sistemas operacionais conforme necessário
                    const char *comando = ""; // Comando vazio para sistemas desconhecidos
                #endif
                printf("website link: ");
                scanf("%s",url);
                char comando_final[256];
                snprintf(comando_final, sizeof(comando_final), comando, url);

                system(comando_final);
                fprintf(arq, "\nopened url: %s", url);
                fseek(arq, 0, SEEK_END);
                long tamanhoAtual = ftell(arq);
                fseek(arq, 0, SEEK_SET);
            }
            if(strcmp(command, "clear") == 0){
                #ifdef _WIN32
                    const char *comando = "cls";
                #elif __linux__
                    const char *comando = "clear";
                #else
                    // Adicione suporte para outros sistemas operacionais conforme necessário
                    const char *comando = ""; // Comando vazio para sistemas desconhecidos
                #endif

                system(comando);
                fprintf(arq, "\nterminal cleared");
                fseek(arq, 0, SEEK_END);
                long tamanhoAtual = ftell(arq);
                fseek(arq, 0, SEEK_SET);
            }
            if(strcmp(command, "link") == 0){
                char url[200];
                printf("important link url: ");
                scanf("%s", url);

                fprintf(arq, "\nimportant link: %s", url);
                fseek(arq, 0, SEEK_END);
                long tamanhoAtual = ftell(arq);
                fseek(arq, 0, SEEK_SET);
            }
            if(strcmp(command,"memorydebug") == 0){
                printf("%d\n", tamanhoAtual);
            }
            if(strcmp(command,"maxmemorydebug") == 0){
                printf("%d\n", limite);
            }
            if(strcmp(command,"createfile") == 0){
                FILE *file;
                
                char filename[500];
                printf("file name and extension: ");
                scanf("%s\n", filename);
                
                file = fopen(filename, "a");
                
                char content[500];
                printf("file content: ");
                scanf("%s\n",content);
                
                fprintf(file,"%s\n",content);
                
                fclose(file);
            }
            if(strcmp(command,"main.py") == 0){
                printf("if you use python, you will lose some 3 of your memory space");
                fprintf(arq,"\n123");
                fseek(arq, 0, SEEK_END);
                long tamanhoAtual = ftell(arq);
                fseek(arq, 0, SEEK_SET);
                system("python main.py") || system("python3 main.py");
            }
            if(strcmp(command,"main.rb") == 0){
                system("ruby main.rb");
            }
            if(strcmp(command,"reset") == 0){
                fclose(arq);
                
                arq = fopen("memory.txt", "w");
                
                fprintf(arq,"");
                
                fclose(arq);
                
                arq = fopen("memory.txt", "a");
            }
            if(strcmp(command,"resetclose") == 0){
                fclose(arq);
                
                arq = fopen("memory.txt", "w");
                
                fprintf(arq,"");
                
                fclose(arq);
                
                arq = fopen("memory.txt", "a");
                running = 0;
            }
            if(strcmp(command,"creat-react-app") == 0){
                system("npx create-react-app myapp") || system("echo you cant use npx to create an react app");
            }
            if(strcmp(command,"recommend") == 0){
                printf("recomended memory limit: 10.000\n");
                printf("the start memories can't be unistalled using reset or resetclose\n");
            }
            if(strcmp(command,"print") == 0){
                char *message[500];
                scanf("%s",message);
                printf("message: %s\n", message);
            }
            if(strcmp(command,"main.js") == 0){
                system("node main.js");
            }
            if(strcmp(command,"help2") == 0){
                printf("memorydebug\n");
                printf("maxmemorydebug\n");
            }
            if(strcmp(command,"app") == 0){
                int runapp = 1;
                char appname[500];
                printf("apps:\n");
                printf("search\n");
                printf("app name: ");
                scanf("%s",appname);
                if(strcmp(appname,"search") == 0){
                    while(runapp){
                        char question[500];
                        printf("what's your question about this OS?\n");
                        printf("about\n");
                        printf("creator\n");
                        printf("version\n");
                        printf("exit\n");
                        printf("question: ");
                        scanf("%s\n",question);
                        if(strcmp(question,"about") == 0){
                            printf("About: this game is my own OS (operating system) and i made him in C\n");
                        }
                        if(strcmp(question,"creator") == 0){
                            printf("Creator: josé icaro\n");
                        }
                        if(strcmp(question,"version") == 0){
                            printf("Version: 1.6\n");
                        }
                        if(strcmp(question,"exit") == 0){
                            runapp = 0;
                        }
                    }
                }
            }
            if(strcmp(command,"main.c") == 0){
                system("gcc -o program main.c");
            }
            if(strcmp(command,"logo") == 0){
                printf("@@@@@@@@@@@@@@@@@&&&&&G55555555555555G&&&&&@@@@@@@@@@@@@@@@@\n");
                printf("@@@@@@@@@@@@@&&&#55555J??????????????J55555#&&&@@@@@@@@@@@@@\n");
                printf("@@@@@@@@@@@&#5YYY??????????????????????????YYY5#&@@@@@@@@@@@\n");
                printf("@@@@@@@@@&#5J???????YGY?5GGGGGGP?????YGY???????J5B#@@@@@@@@@\n");
                printf("@@@@@@@#BJ!?????????P@G?B@GPPPP5???YBGPGBY???????J5B#@@@@@@@\n");
                printf("@@@@@#GJ~^:7????????5@G?B@Y????????P@&B&@5?????????J5G#@@@@@\n");
                printf("@@@&P5J!:^:7????????P@G?B@5JJJJJ?Y&GJYYYJB&J??????????5P&@@@\n");
                printf("@@&#5Y?!:^:7????????5&P?G&#####B?Y&G?????B&J??????????Y5#&@@\n");
                printf("@&P5???!:::7???????????????JJJJ?????????????????????????5P&@\n");
                printf("@&P5???!:~~7?7!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!7?????5P&@\n");
                printf("BBYJ???!:7???^::::::::::::::::::::::::::::::::::::~?????JYBB\n");
                printf("55?????!:!???5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5???????55\n");
                printf("55??????7????&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B???????55\n");
                printf("55???????????&@@#~7&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P^~~^^^^YP\n");
                printf("PY^^^~777????&@@@&G~JB#@@@@@@@@@@@@@@@@@@@@@@@@@@@B7??~^^^YP\n");
                printf("PY~~~~~~~7???&@@@@&PJ~P@@@@@@@@@@@@@@@@@@@@@@@@@@@B???????55\n");
                printf("55???????????&@@&5J!5@BYYYYYY5@@@@@@@@@@@@@@@@@@@@B???????55\n");
                printf("BBYJ?????????&@@&?5@@@G??????J&@@@@@@@@@@@@@@@@@@@B?????JYBB\n");
                printf("@&P5?????????&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B?????5P&@\n");
                printf("@&P5?????????YYYYYYYYYYYYYYYYYYYYYYYYYYY5?7Y5YYYY5Y?????5P&@\n");
                printf("@@&#5Y???????????????????????????????????^:7??????????Y5#&@@\n");
                printf("@@@&P5???????????????????????????????????~:^^?????????5P&@@@\n");
                printf("@@@@@#G5J????????????????????????????????~::^??????J5G#@@@@@\n");
                printf("@@@@@@@#B5J??????????????????????????????~:^^????J5B#@@@@@@@\n");
                printf("@@@@@@@@@#B5J????????????????????????????~::^??J5B#@@@@@@@@@\n");
                printf("@@@@@@@@@@@&#5YYY????????????????????????~:?JY5#&@@@@@@@@@@@\n");
                printf("@@@@@@@@@@@@@&&&#55555J??????????????J555YY#&&&@@@@@@@@@@@@@\n");
                printf("@@@@@@@@@@@@@@@@@&&&&&G55555555555555G&&&&&@@@@@@@@@@@@@@@@@\n");
            }
        } else {
            if(tamanhoAtual > limite){
                printf("Storage limit reached. Cannot perform more operations.\n");
                running = 0;  // Encerra o loop se o limite for atingido
            }
        }
    }
    
    fclose(arq);
    
    return 0;
}
