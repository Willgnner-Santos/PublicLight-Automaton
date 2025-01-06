//Projeto Controle Autômato das Luzes das Ruas.
//Trabalho final da disciplina Microcontroladores e Microprocessadores.
//Professor Carlos Alexandre Ferreira de Lima.
//Turma: A01 - CMP1089.
//Alunos: Douglas Vieira; Gabriel Mendes; Wemerson Moura e Willgnner Ferreira.

int light;
void read_ldr()
{
   unsigned int adc_value=0;
   adc_value=ADC_Read(0);
   light = 100 - adc_value/10.24;
   if(light>=80) // Caso a luz apresente 80%, ela deve desligar automaticamente.
     {
       PORTB.F1=0;
     }
        else
            {
               PORTB.F1=1;
            }
}
void main()
{
   TRISB=0X00;
   PORTB=0X00;
   Adc_Init();

       while (1)
             {
                read_ldr();
             }
}