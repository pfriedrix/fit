using System;
using System.Globalization;
using Microsoft.VisualBasic;

namespace lesson1
{
    public enum Color
    {
        red, 
        orange, 
        yellow,
        green,
        blue, 
        blue_dark,
        purple,
    }
    class Interface
    {
        public int a, b;
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
                    PrintOutInfo();
                    break;
                case 2:
                    CountSquareRectangle(a, b);
                    break;
                case 3:
                    CountLinearEquelation(a, b);
                    break;
                case 4:
                    GoThroughFilter(a, b);
                    break;
                case 5:
                    ChooseColor();
                    break;
                case 6:
                    CalcMidEstim();
                    break;
            }
        }
        
        private void PrintOutInfo()
        {
            Console.WriteLine("FULL NAME: Ivan Romancev");
            Console.WriteLine("AGE: 17");
            Console.WriteLine("GROUP: IPZ-12");
            Console.WriteLine("COURSE: 1");
            Console.WriteLine("EMAIL: dnl.krsvch@gmail.com");
        }

        private void CountSquareRectangle(int a, int b)
        {
            Console.WriteLine("Площа: " + a * b);
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
            x--;
            Console.WriteLine("Колір: " + (Color)x + " hex: " + hex);
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
            int a, b;
            Interface instance = new Interface();
            instance.PrintOutMenu();
            Console.WriteLine("Введіть a та b, що є значенням рівнянням: ");
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());
            instance.a = a;
            instance.b = b;
            while (true)
            {
                instance.CallByOption();
            }
           
        }
    }

    
} 