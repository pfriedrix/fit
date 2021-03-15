using System;
using System.Globalization;
using System.Linq;
using Microsoft.VisualBasic;

namespace lesson1
{
    
    class Interface
    {
        static int length = Convert.ToInt32(Console.ReadLine());
        int[] arr = new int[length];
        Random random = new Random();
        public void PrintOutMenu()
        {
            Console.WriteLine("1) task1");
            Console.WriteLine("2) task2");
            Console.WriteLine("3) task3");
            Console.WriteLine("4) task4");
            Console.WriteLine("5) task5");
            Console.WriteLine("6) task6");
            Console.WriteLine("7) task7");
            Console.WriteLine("8) task8");
            Console.WriteLine("9) task9");
        }

        private int GetOption()
        {
            int option;
            Console.Write("Введіть число, що співпадає з номером зі списка: ");
            option = Convert.ToInt32(Console.ReadLine());
            if (option > 9)
            {
                Environment.Exit(0);
            }
            return option >= 1 && option <= 9 ? option : GetOption();
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
                    CountPrimeNumbers();
                    break;
                case 3:
                    SortArrByTemplate();
                    break;
                case 4:
                    MinAndMaxNumb();
                    break;
                case 5:
                    SearchInRange();
                    break;
                case 6:
                    Task6();
                    break;
                case 7:
                    Task7();
                    break;
                case 8:
                    CalcNoLinear();
                    break;
                case 9:
                    CheckSyntax();
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
            Console.WriteLine("{0}", string.Join(", ", arr));
            
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

        private void CountPrimeNumbers()
        {
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int counter = 0;
            for (int i = 0; i < length; i++)
            {
                arr[i] = random.Next(0, 100);
            }
            Console.WriteLine("{0}", string.Join(", ", arr));
            
            for (int i = range[0]-1; i < range[1]; i++)
            {
                if (isPrime(arr[i]))
                {
                    counter++;
                    Console.WriteLine(arr[i]);
                }
            }

            if (counter == 0)
            {
                Console.WriteLine("Тут не має простих чисел");
            }

        }

        private bool isPrime(int numb)
        {
            for (int i = 2; i < numb; i++)
            {
                if (numb % i == 0)
                {
                    return false;
                }
            }

            return true;
        }

        private void SortArrByTemplate()
        {
            int seperator = 0;
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int i = 0; i < length; i++)
            {
                arr[i] = random.Next(range[0], range[1]);
            }
            Console.WriteLine("{0}", string.Join(", ", arr));
            for (int i = 0; i < length; i++)
            {
                if (seperator == 0)
                {
                    int q = negativeNumb(i);
                    int temp = arr[i];
                    arr[i] = arr[q];
                    arr[q] = temp;
                    seperator++;
                }
                else if (seperator == 1)
                {
                    int q = positiveNumb(i);
                    int temp = arr[i];
                    arr[i] = arr[q];
                    arr[q] = temp;
                    seperator++;
                }
                else if (seperator == 2)
                {
                    int q = zeroNumb(i);
                    int temp = arr[i];
                    arr[i] = arr[q];
                    arr[q] = temp;
                    seperator = 0;
                }
            }
            Console.WriteLine("{0}", string.Join(", ", arr));
        }

        int negativeNumb(int start)
        {
            for (int i = start; i < length; i++)
            {
                if (arr[i] < 0)
                {
                    return i;
                }
            }

            return start;
        }
        
        int positiveNumb(int start)
        {
            for (int i = start; i < length; i++)
            {
                if (arr[i] > 0)
                {
                    return i;
                }
            }
            return start;
        }
        
        int zeroNumb(int start)
        {
            for (int i = start; i < length; i++)
            {
                if (arr[i] == 0)
                {
                    return i;
                }
            }
            return start;
        }

        private void MinAndMaxNumb()
        {
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int i = 0; i < length; i++)
            {
                arr[i] = random.Next(range[0], range[1]);
            }
            Console.WriteLine("{0}", string.Join(", ", arr));
            int min = arr[0], min_index = 0, max = arr[0], max_index = 0;
            for (int i = 1; i < length; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                    max_index = i;
                }

                if (arr[i] < min)
                {
                    min = arr[i];
                    min_index = i;
                }
            }
            Console.WriteLine("Мінімальне: індекс - {0} значення - {1}", min_index, min);
            Console.WriteLine("Максимальне: індекс - {0} значення - {1}", max_index, max);
        }
    

        private void SearchInRange()
        {
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for (int i = 0; i < length; i++)
            {
                arr[i] = i;
            }
            Console.WriteLine("{0}", string.Join(", ", arr));
            int counter = 0;
            for (int i = range[0]; i <= range[1]; i++)
            {
                int index = Array.BinarySearch(arr, i);
                if (index >= 0)
                {
                    Console.WriteLine("Число {0} було знайдено з індексом {1}", i, index);
                    counter++;
                }
            }

            if (counter == 0)
            {
                Console.WriteLine("Нічого не знайшли");
            }
        }

        
        private void CheckSyntax()
        {
            var line = Console.ReadLine();
            int[] counter = new int[3];
            bool error = false;
            foreach (char c in line)
            {
                if (c == '(' || c == ')')
                {
                    if (c == '(') counter[0]++;
                    else
                    {
                        if (counter[0] <= 0)
                        {
                            error = true;
                            break;
                        }

                        counter[0]--;
                    }
                }
                else if (c == '[' || c == ']')
                {
                    if (c == '[') counter[1]++;
                    else
                    {
                        if (counter[1] <= 0)
                        {
                            error = true;
                            break;
                        }

                        counter[1]--;
                    }
                }
                else if (c == '{' || c == '}')
                {
                    if (c == '{') counter[2]++;
                    else
                    {
                        if (counter[2] <= 0)
                        {
                            error = true;
                            break;
                        }

                        counter[2]--;
                    }
                }
                else
                {
                    continue;
                }
            }
            

            if (counter[0] != 0) error = true;
            if (counter[1] != 0) error = true;
            if (counter[2] != 0) error = true;

            if (error)
            {
                Console.WriteLine("Syntax Error");
            }
            else
            {
                Console.WriteLine("Correct");
            }
        }

        private void CalcNoLinear()
        {

            double a = 0.4, b = 1, x = Math.Abs(b - a) / 2;
            const double eps = 0.001;
            for (; Math.Abs(b-a) > eps; ) {
                if (Math.Abs(F(x)) > Math.Abs(F(a))) a = x; else b = x;
                x = (a - b) / 2;
            }
            Console.WriteLine(x);
            Console.WriteLine(F(x));
        }

        private void Task6()
        {
           
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[,] array = new int[range[0], range[1]];
            for (int i = 0; i < range[0]; i++)
            {
                for (int j = 0; j < range[1]; j++)
                {
                    if (i == 0 && j == 0) continue;
                    if (i == 0) array[i, j] = j;
                    if (j == 0) array[i, j] = i;
                }
            }

            for (int i = 0; i < range[0]; i++)
            {
                for (int j = 0; j < range[1]; j++)
                {
                    if (i == 0 || j == 0) continue;
                    array[i, j] = random.Next(-5, 10);
                }
            }

            Console.WriteLine("-----------------------");
            
            for (int i = 0; i < range[0]; i++)
            {
                for (int j = 0; j < range[1]; j++)
                {
                    Console.Write("{0} ", array[i, j]);
                }
                Console.Write(Environment.NewLine);
            }
            
            for (int i = 1; i < range[1]; i++)
            {
                int sum = 0;
                for (int j = 1; j < range[0]; j++)
                {
                    sum += array[j, i];
                }
                if (sum > 0)
                {
                    Console.WriteLine("Товар {0} приносить прибуток з індексом - {1} ", array[0, i], "0, " + i);
                }
                Console.WriteLine("Товар {0}: прибуток - {1} ", array[0, i], sum);
            }
            Console.Write(Environment.NewLine);

            int overall = 0;
            for (int i = 1; i < range[1]; i++)
            {
                for (int j = 1; j < range[0]; j++)
                {
                    overall += array[j, i];
                }
            }
            Console.WriteLine("Весь прибуток: {0}", overall);
        }

        private void Task7()
        {
            var range = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int[,] array = new int[range[0], range[1]];
            for (int i = 0; i < range[0]; i++)
            {
                for (int j = 0; j < range[1]; j++)
                {
                    array[i, j] = random.Next(1, 20);
                }
            }

            for (int i = 0; i < range[0]; i++)
            {
                for (int j = 0; j < range[1]; j++)
                {
                    Console.Write("{0} ", array[i, j]);
                }
                Console.Write(Environment.NewLine);
            }
            int min = array[0, 0];
            var min_index = new int[2];
            
            for (int i = 0; i < range[0]; i++)
            {
                for (int j = 0; j < range[1]; j++)
                {
                    if (array[i, j] < min)
                    {
                        min = array[i, j];
                        min_index[0] = i;
                        min_index[1] = j;
                    }
                }
            }
            Console.WriteLine("індекс - {0} значення - {1}", string.Join(", ", min_index), min);

            array = TrimArray(min_index[0], min_index[1], array);
            
            Console.WriteLine("-----------------------");
            
            for (int i = 0; i < range[0]-1; i++)
            {
                for (int j = 0; j < range[1]-1; j++)
                {
                    Console.Write("{0} ", array[i, j]);
                }
                Console.Write(Environment.NewLine);
            }
        }
        
        public static int[,] TrimArray(int rowToRemove, int columnToRemove, int[,] originalArray)
        {
            int[,] result = new int[originalArray.GetLength(0) - 1, originalArray.GetLength(1) - 1];

            for (int i = 0, j = 0; i < originalArray.GetLength(0); i++)
            {
                if (i == rowToRemove)
                    continue;

                for (int k = 0, u = 0; k < originalArray.GetLength(1); k++)
                {
                    if (k == columnToRemove)
                        continue;

                    result[j, u] = originalArray[i, k];
                    u++;
                }
                j++;
            }

            return result;
        }

        public static double F(double x)
        {
            return Math.Pow(x * x - 5 * x + 7, 2) - (x - 2) * (x - 3);
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