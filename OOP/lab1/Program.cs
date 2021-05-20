using System;
using System.Globalization;
using Microsoft.VisualBasic;

namespace lesson1
{
    

    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[100];
            Task1(array, 10);
            array.GetLength();
        }
        
        static void Task1(int[] array, int length)
        {
            var rand = new Random();
            Console.WriteLine("Start of range: ");
            int start = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("End of range: ");
            int end = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("  Your array: ");
            for (int i = 0; i < length; i++)
            {
                array[i] = rand.Next(start,end);
                Console.Write(array[i] + " ");
            }
            Console.WriteLine("\n");
            int j, step;
            int tmp;
            for (step = length / 2; step > 0; step /= 2)
            for (int i = step; i < length; i++)
            {
                tmp = array[i];
                for (j = i; j >= step; j -= step)
                {
                    if (tmp < array[j - step])
                        array[j] = array[j - step];
                    else
                        break;
                }
                array[j] = tmp;
            }
            Console.WriteLine("  Sorted array: ");
            for (int i = 0; i < length; i++) Console.Write(array[i] + " ");
    
            Console.WriteLine("\n====================================");
            
            int value = 0, index = -1;
            Console.WriteLine("Enter a value you wanna find:");
            value = Convert.ToInt32(Console.ReadLine());
            index = Array.BinarySearch(array, value);
            if (index >= 0) Console.WriteLine("Element " + value + " found at index " + index);
            else Console.WriteLine("There is no " + value + " in the array..");
        }
        
        
    }

    
} 