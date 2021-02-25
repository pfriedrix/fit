using System;
using System.Globalization;
using System.Linq;
using Microsoft.VisualBasic;

namespace lesson1
{
    
    class Interface
    {
        static int length = Convert.ToInt32(Console.ReadLine());
        List<int> arr= new List<int>();
        Random random = new Random();
        public void PrintOutMenu()
        {
            Console.WriteLine("1) Вивести на екран анкентні дані");
            Console.WriteLine("2) Обчислити площу прямокутника");
            Console.WriteLine("3) Обчислити рівняння");
            Console.WriteLine("4) Обчислити значення функції");
            Console.WriteLine("5) Вибрати колір");
            Console.WriteLine("6) Середня оцінка суддів");
        }

        private int GetOption()
        {
            int option;
            Console.Write("Введіть число, що співпадає з номером зі списка: ");
            option = Convert.ToInt32(Console.ReadLine());
            if (option > 6)
            {
                Environment.Exit(0);
            }
            return option >= 1 && option <= 6 ? option : GetOption();
        }

        public void CallByOption()
        {

            int option = GetOption();
            switch (option)
            {
                case 1:
                    SortArr();
                    break;
                case 2:
                    
                    break;
                case 3:
                    
                    break;
                case 4:
                   
                    break;
                case 5:
                   
                    break;
                case 6:
                    ч
                    break;
            }
        }
        
        private void SortArr()
        {
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int i = 0; i < length; i++)
            {
                arr[i] = random.Next(range[0], range[1]);
            }
            Console.WriteLine("{0}", string.Join(", ", ));
            
            for (int step = length / 2; step > 0; step /= 2) {
                for (int i = step; i < length; i++) {
                    for (int j = i - step; j >= 0 && arr[j] > arr[j + step] ; j -= step) {
                        int x = arr[j];
                        arr[j] = arr[j + step];
                        arr[j + step] = x;
                    }
                }
            }
            Console.WriteLine("{0}", string.Join(", ", arr));
        }

        private void CountSquareRectangle()
        {
            int[] prime_numbers = arr;
            for (int i = 0; i < length; i++)
            {
                if (prime_numbers[i] % 2 == 0 || prime_numbers[i] % 3 == 0)
                {
                    
                }
                else if (prime_numbers[i] == 5)
                {
                    continue;
                }
                else if (prime_numbers[i] % 5 == 0)
                {
                    prime_numbers.Remove(i);
                }
            }
        }

        private void CountLinearEquelation(int a, int b)
        {
            double equelation = 0;
            if (!(a == b))
            {
                for (int i = 0; i < 100; i++)
                {
                    equelation = equelation + (Math.Pow((-1), i) * Math.Pow(a, (2 * i + 1))) / Factorial(2 * i + 1);
                }
                equelation = (1 - a) * (a + b) / (a - b) + equelation;
                Console.WriteLine("X: " + equelation);
            }
            else
            {
                Console.WriteLine("Devision");
            }
            
        }

        private double Factorial(int n)
        {
            double tmp = 1;
            for (int i = 1; i <= n; i++)
            {
                tmp *= i;
            }

            return tmp;
        }
    

        private void GoThroughFilter(int a, int b)
        {
            double result;
            if (b == 0) result = 0;
            else if (a > b) result = Math.Pow(a, 2) / Math.Pow(b, 2);
            else if (a < b) result = Math.Pow(b, 2) - Math.Pow(a, 2);
            else result = 1;
            Console.WriteLine(string.Format("Результат: {0}", result));
        }

        private void ChooseColor()
        {
            int x;
            Console.Write("Введіть x: ");
            x = Convert.ToInt32(Console.ReadLine());
            string hex = "";
            switch (x)
            {
                case 1:
                    hex = "0xff0000";
                    break;
                case 2:
                    hex = "0xffa500";
                    break;
                case 3:
                    hex = "0xffff00";
                    break;
                case 4:
                    hex = "0x008000";
                    break;
                case 5:
                    hex = "0x0066ff";
                    break;
                case 6:
                    hex = "0x0000ff";
                    break;
                case 7:
                    hex = "0x800080";
                    break;
            }
        }

        private void CalcMidEstim()
        {
            int judges;
            Console.Write("Введіть кількість суддів: ");
            judges = Convert.ToInt32(Console.ReadLine());
            
            int mark, sum, min_el, max_el;
            Console.Write("Введіть оцінку: ");
            mark = Convert.ToInt32(Console.ReadLine());
            sum = mark; min_el = mark; max_el = mark;
            int i = 1; 
            while (i < judges)
            {
                Console.Write("Введіть оцінку: ");
                mark = Convert.ToInt32(Console.ReadLine());
                sum += mark;
                
                min_el = mark < min_el ? mark : min_el;
                max_el = mark > max_el ? mark : max_el;
                i++;
            }
            Console.WriteLine("Оцінка: " + (sum - min_el - max_el) / (judges - 2));
        }
    }
    

    class Program
    {
        static void Main(string[] args)
        {
            Interface instance = new Interface();
            instance.PrintOutMenu();
            while (true)
            {
                instance.CallByOption();
            }
           
        }
    }

    
} 