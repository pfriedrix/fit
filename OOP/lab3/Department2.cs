using System;

namespace lab3
{
    public partial class Department
    {
        public void annualIncome()
        {
            Random random = new Random();
            Console.WriteLine("Each year you will get: " + random.Next(0, 1000));
        }
    }
}