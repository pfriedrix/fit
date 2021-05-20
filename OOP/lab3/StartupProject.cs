using System;
using System.Linq;

namespace lab3
{
    public class StartupProject
    {
        static int length;
        static int[] arr;

        static Random random = new Random();

        public StartupProject()
        {
            Console.WriteLine("input length: ");
            length = Convert.ToInt32(Console.ReadLine());
            arr = new int[length];
        }
        public static void PrintOutMenu()
        {
            Console.WriteLine("1) task1");
            Console.WriteLine("2) task2");
            Console.WriteLine("3) task3");
        }

        private static int GetOption()
        {
            int option;
            Console.Write("Введіть число, що співпадає з номером зі списка: ");
            option = Convert.ToInt32(Console.ReadLine());
            if (option > 9)
            {
                Environment.Exit(0);
            }
            return option >= 1 && option <= 3 ? option : GetOption();
        }

        public static void CallByOption()
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
            }
        }
        private static void SortArr()
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
        
        private static void CountPrimeNumbers()
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
        
        private static bool isPrime(int numb)
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
        
        private static void SortArrByTemplate()
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

        static int negativeNumb(int start)
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
        
        static int positiveNumb(int start)
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
        
        static int zeroNumb(int start)
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

    }
}