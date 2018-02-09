/*UVa 1225
* 给出一个物质的分子式（不带括号），求分子量。本题中的分子只包含4种原子，分别为C，H，O，N，
* 原子量分别为12.01，1.008，16.00，14.01（单位：g/mol）。例如，C6H5OH的分子量为94.108g/mol。
*/
#include <cstdio>
#include <cctype> /* isdigit() */

int main(void){
    double weight = 0;
    double current = 0;
    int number = 0;
    int c;
    while((c = getchar()) != EOF){
        if(isdigit(c)){
            number = number*10 + (c - '0');
        }else{
            if(number!=0){
                weight += (number-1)*current;
                number = 0;
            }
            switch(c){
            case 'C': current = 12.01; break;
            case 'H': current = 1.008; break;
            case 'O': current = 16.00; break;
            case 'N': current = 14.01; break;
            default: current = 0; break;
            }
            weight += current;
        }
    }
    printf("%f\n", weight);
    return 0;
}