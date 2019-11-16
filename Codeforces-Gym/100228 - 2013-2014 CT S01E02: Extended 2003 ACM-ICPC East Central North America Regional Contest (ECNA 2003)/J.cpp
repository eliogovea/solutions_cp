// 2013-2014 CT S01E02: Extended 2003 ACM-ICPC East Central North America Regional Contest (ECNA 2003)
// 100228J

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication7
{
    class Program
    {
        static String abc = "abcdefghijklmnopqrstuvwxyz";
        static int[] arrayA;
        
        static void Main(string[] args)
        {
            String a = Console.ReadLine();

            while (a != null)
            {
                arrayA = new int[abc.Length];
                
                String b = Console.ReadLine();

                setArrayA(a);

                String x = "";

                for (int i = 0; i < b.Length; i++)
                {
                    int ind = BusquedaBinaria(b[i]);

                    if (arrayA[ind] > 0)
                    {
                        x += b[i];
                        arrayA[ind]--;
                    }
                }

                char[] output = x.ToCharArray();

                Array.Sort(output);

                for (int i = 0; i < output.Length; i++)
                    Console.Write(output[i]);
                Console.WriteLine();
                a = Console.ReadLine();
            }
        }

        static void setArrayA(String s)
        { 
            for(int i = 0; i < s.Length; i++)
            {
                arrayA[BusquedaBinaria(s[i])]++;
            }
        }

        static int BusquedaBinaria(char x)
        {
            int inicio = 0;
            int fin = 25;
            int medio = 0;

            for (int i = 0; i < 26; i++)
            {
                if (inicio == fin)
                {
                    if (abc[inicio] == x)
                        return inicio;
                    else return -1;
                }

                medio = (fin + inicio) / 2;

                if (abc[medio] == x) return medio;

                if (abc[medio] > x) fin = medio - 1;

                else inicio = medio + 1;
            }

            return -1;
        }
    }
}
