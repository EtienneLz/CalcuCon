#include <stdlib.h>
#include <stdio.h>



void create()
{
  FILE* fichier = NULL;
  remove("CalcuCon.c");
  fichier = fopen("CalcuCon.c","w");

  float nb1 = 0;
  float nb2 = 0;
  char *sign = "+-/*";
  int i = 0;

  if (fichier != NULL)
  {
    fprintf(fichier, "#include <stdio.h>\n\nvoid clearBuffer()\n{\n");
    fprintf(fichier, "\tint c;\n");
    fprintf(fichier, "\twhile ( (c = getchar()) != '\\n' && c != EOF);\n}\n\n");
    fprintf(fichier, "int main(void)\n{\n");
    fprintf(fichier, "\tfloat num1;\n\tfloat num2;\n\tchar sign;\n");
    fprintf(fichier, "\tprintf(\"Entrez le premier nombre: \\n\");");
    fprintf(fichier, "\n\tscanf(\"%%f\", &num1);\n");
    fprintf(fichier, "\tclearBuffer();\n");
    fprintf(fichier, "\tprintf(\"Entrez le signe: \\n\");");
    fprintf(fichier, "\n\tscanf(\"%%c\", &sign);\n");
    fprintf(fichier, "\tclearBuffer();\n");
    fprintf(fichier, "\tprintf(\"Entrez le second nombre: \\n\");\n");
    fprintf(fichier, "\tscanf(\"%%f\", &num2);\n");
    while (i < 4)
    {
      while (nb1 <= 100)
      {
        while (nb2 <= 100)
        {
          fprintf(fichier, "\tif ((num1 == %f) && (num2 == %f) && (sign == '%c'))\n", nb1, nb2, sign[i]);
          if (i == 0)
          {
            fprintf(fichier, "\t\tprintf(\"%f %c %f = %f \\n\");\n", nb1, sign[i], nb2, nb1+nb2);
          }
          if (i == 1)
          {
            fprintf(fichier, "\t\tprintf(\"%f %c %f = %f \\n\");\n", nb1, sign[i], nb2, nb1-nb2);
          }
          if (i == 2)
          {
            fprintf(fichier, "\t\tprintf(\"%f %c %f = %f \\n\");\n", nb1, sign[i], nb2, nb1/nb2);
          }
          if (i == 3)
          {
            fprintf(fichier, "\t\tprintf(\"%f %c %f = %f \\n\");\n", nb1, sign[i], nb2, nb1*nb2);
          }
          nb2++;
        }
        if (i == 2)
          nb2 = 1;
        else
          nb2 = 0;
        nb1++;
      }
      nb1 = 0;
      i++;
      if (i == 2)
        nb2 = 1;
    }
    fprintf(fichier, "\tprintf(\"Merci d'avoir utiliser @CalcuCon TM\nCopyright Etienne Louchez 2021)\");\n");
    fprintf(fichier, "}\n");
    fclose(fichier);
  }
}

int main()
{
  create();
  return (0);
}
