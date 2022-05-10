#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/* informações gerais:
1 litro = 2.35€
1 litro = 35km
combustivel gasto = (km viagem) / 35 = numero de Litros.
10km = 0.80€
ida = ((km de viagem) / 10) * 0.80€ + classe escolhida
ida e volta = ((((km de viagem) / 10) * 0.80€) * 2) - 70€ + classe escolhida 
** classe económica (10€)
classe média(35€)
classe VIP (150€) **/

void menu()
{
  
puts("+--------Bem-vindo(a) DILUA AIRLINES--------+");
puts("|                                           |");  
puts("| Localizado no aeroporto Humberto Delgado, |");  
puts("| Lisboa, Portugal.                         |"); 
puts("|                                           |");
puts("| Insira a tecla correspondente a opção.    |");  
puts("|                                           |");
puts("| 1 - Comprar Bilhete.                      |");
puts("| 2 - Informações adicionais.               |"); 
puts("|                                           |");
puts("| 9 - Sair                                  |");
puts("| Obrigado pela preferência                 |");  
puts("+-------------------------------------------+");
  
}
void menuDestinos()
{
  puts("+-----------------------------Os destinos são-----------------------------+");
  puts("|                                                                         |");
  puts("|  Ponto de partida: Aeroporto Internacional de Lisboa | Humberto Delgado |"); //ponto de partida
  puts("|                                                                         |");
  puts("|  País |Alemanha| Cidade |Frankfurt     |   Cod.Destino |A|              |"); //2320km
  puts("|  País |Portugal| Cidade |Porto         |   Cod.Destino |P|              |"); //310km
  puts("|  País |Brasil  | Cidade |Rio de Janeiro|   Cod.Destino |B|              |"); //7710 km  
  puts("|  País |E.U.A   | Cidade |New York      |   Cod.Destino |E|              |"); //5419 km 
  puts("|  País |China   | Cidade |Xangai        |   Cod.Destino |C|              |"); //10 703 km
  puts("|                                                                         |");  
  puts("+-------------------------------------------------------------------------+");
}
void calculoBilhete(char opcaoClasse,char idaOuVolta, float total, int kmsViagem)
{
   if((idaOuVolta == 'i' || idaOuVolta == 'I') && (opcaoClasse == 'e' || opcaoClasse == 'E'))
    {
        total = ((kmsViagem / 10) * 0.80) + 10;
          printf("Valor bilhete (só ida + classe Economica): %0.2f €\n", total); 
    }
    else if ((idaOuVolta == 'i' || idaOuVolta == 'I') && (opcaoClasse == 'm' || opcaoClasse == 'M'))
    {
      total = ((kmsViagem / 10) * 0.80) + 30;
      printf("Valor bilhete (só ida + classe Media): %0.2f €\n", total);
    }
    else if ((idaOuVolta == 'i' || idaOuVolta == 'I') && (opcaoClasse == 'v' || opcaoClasse == 'V'))
    {
      total = ((kmsViagem / 10) * 0.80) + 150;
      printf("Valor bilhete (só ida + classe V.I.P): %0.2f €\n", total);
    }
   
    else if((idaOuVolta == 'v' || idaOuVolta == 'V') && (opcaoClasse == 'E' || opcaoClasse == 'e'))
    {
      total = ((((kmsViagem / 10) * 0.80) + 10) * 2) - 70;
      printf("Valor bilhete (ida e volta + classe Economica): %0.2f €\n", total);
    }
    else if ((idaOuVolta == 'v' || idaOuVolta == 'V') && (opcaoClasse == 'M' || opcaoClasse == 'm'))
    {
      total = ((((kmsViagem / 10) * 0.80) + 30) * 2) - 70;
      printf("Valor bilhete (ida e volta + classe Media): %0.2f €\n", total);
    }
    else if ((idaOuVolta == 'v' || idaOuVolta == 'V') && (opcaoClasse == 'v' || opcaoClasse == 'V')){
      total = ((((kmsViagem / 10) * 0.80) + 150) * 2) - 70;
      printf("Valor bilhete (ida e volta + classe V.I.P): %0.2f €\n", total);  
    }
}


int main(void){

// variáveis
  
float valorCombustivel = 2.35, litrosDeCombustivel, combustivelGasto, total = 0.0; 
  
int idade, totalCombustivel, kmsViagem, numeroIdentificacao, numeroTelemovel, cEco = 10, cMed = 35, cVIP = 150;
  
char opcao, opcao2, codDestino, idaOuVolta, codDestinoGrande, opcaoClasse;  
  
char nome[20] = "", classe[20] = "", apelido[20] = "", email[60] = "", destino[40] = "";


menu(); // display do menu

  do{ // inicio do ciclo
  
scanf(" %c", &opcao); 
  
switch(opcao){

  if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 9){
    puts("Opção inválida.");
  }

  case '2':
    
    puts("+--------------------------Informações adicionais-------------------------+");
    puts("|                                                                         |");
    puts("|  CLASSES:                                                               |"); 
    puts("|  Económica: refeição completa, refrigerante e sobremesa.                |");
    puts("|  Média: refeição completa, bebidas, sobremesa, e conforto adicional     |"); 
    puts("|  V.I.P: refeição completa, bebidas, sobremesa, assentos TOP-COMFORT*.   |"); 
    puts("|                                                                         |"); 
    puts("|  *Nossos assentos TOP-COMFORT te garantem uma viagem sem estresse,      |"); 
    puts("|  com assentos privados, direito a brindes excluisvos, e WI-FI.          |"); 
    puts("|                                                                         |"); 
    puts("|  CONTACTOS:                                                             |");  
    puts("|  Linha de apoio: 212-402-980                                            |"); 
    puts("|  E-mail: airtrip@dilua.pt                                               |"); 
    puts("|                                                                         |");
    puts("|  OBRIGADO POR VOAR CONNOSCO!                                            |");
    puts("|  Para voltar ao menu inicial digite (z)                                 |");
    puts("+-------------------------------------------------------------------------+");
    
     do{
      scanf(" %c", &opcao2);
      if(opcao2 == 'z' || opcao2 == 'Z'){
        return main();
      }else{
        printf("Invalid Response.\n");
      }
      }while(opcao2 != 'z' && opcao2 != 'Z');
  break;
    
    return 0;
    break;
  
  case '9': // exit
    puts("Obrigado pela atenção, volte sempre!");
    return 0;
    break;

  case '1':
    puts("Necessitamos de alguns dados pessoais, estimado consumidor.\n");

  puts("Nome: (Ex: Jacinto)");
    scanf("%s", nome);

  puts("Apelido: (Ex: Rosa)");
    scanf("%s", apelido);

  puts("Idade:");
    scanf("%d", &idade);

  puts("Número do BI:");
    scanf("%d", &numeroIdentificacao);

  puts("Número de telemóvel: (Ex: 999999999)");
    scanf("%d", &numeroTelemovel);

  puts("Email: (Ex: seunome@mail.pt)");
    scanf("%s", email);

    
  puts("\nObrigado, agora por favor selecione o destino pretendido.");
  
    menuDestinos();
    
   
        puts("Por favor introduza o código do destino pretendido.");
   

    do{
        scanf(" %c", &codDestino);
      if(codDestino != 'a' && codDestino != 'A' && codDestino != 'p' && codDestino != 'P' && codDestino != 'b' && codDestino != 'B' && codDestino != 'e' && codDestino != 'E' && codDestino != 'c' && codDestino != 'C')
      {
        puts("Opção inválida.");
      } else{
        break;
      }
   
    } while(codDestino != 'a' && codDestino != 'A' && codDestino != 'p' && codDestino != 'P' && codDestino != 'b' && codDestino != 'B' && codDestino != 'e' && codDestino != 'E' && codDestino != 'c' && codDestino != 'C');  

        puts("Deseja que seja uma viagem só de ida(i), ou ida e volta(v)?"); 

    do{
      scanf(" %c", &idaOuVolta);
      if(idaOuVolta != 'i' && idaOuVolta != 'v')
      {
        puts("Opção inválida.");
      }
      else
      {
        break;
      }  
    } while(idaOuVolta != 'i' && idaOuVolta != 'v');

    
    puts("+--------------Classes--------------+");
    puts("|                                   |");
    puts("|Escolha uma das seguintes opções:  |");
    puts("|                                   |");
    puts("|opção 'E' - Económica = 10€        |");
    puts("|opção 'M' - Média = 30€            |");
    puts("|opção 'V' - VIP = 150€             |");
    puts("+-----------------------------------+");

    scanf(" %c", &opcaoClasse);

    puts("Iremos então calcular o valor do bilhete...");
    // destino: Alemanha
   switch(codDestino){
     case 'A':kmsViagem = 2320;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
     
     case 'a':kmsViagem = 2320;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
    // destino: Portugal  
     case 'P':kmsViagem = 310;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
     case 'p':kmsViagem = 310;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
    // destino: Brasil  
     case 'B':kmsViagem = 7710;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
     case 'b':kmsViagem = 7710;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
    // destino: Estados Unidos    
     case 'E':kmsViagem = 5419;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
     case 'e':kmsViagem = 5419;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
    // destino: China
     case 'C':kmsViagem = 10703;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
     case 'c':kmsViagem = 10703;
       calculoBilhete(opcaoClasse, idaOuVolta, total, kmsViagem);
         puts("Obrigado por comprar connosco! Volte sempre.");
       return 0;
           break;
     
    // nenhuma das opções
     default:
       puts("Opção inválida.");
       scanf(" %c", &codDestino);
       break;
    }

  
  }
}while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 9); // fim do ciclo

return 0; 
}