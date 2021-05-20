using System;
using System.IO;
using System.Text;

namespace lab3
{
    public class Company
    {
        string name;
        int rating;
        int workers;
        int income;

        public string Name
        {
            get => name;
            set => name = value;
        }

        public int Rating
        {
            get => rating;
            set => rating += 1;
        }

        public int Workers
        {
            get => workers;
            set => workers += 1;
        }

        public int Income
        {
            get => income;
            set => income += 1000;
        }

        public Company() {
            this.name = "";
            this.rating = 0;
            this.workers = 0;
            this.income = 0;
        }

        public Company(string name, int rating, int workers, int income)
        {
            this.name = name;
            this.rating = rating;
            this.workers = workers;
            this.income = income;
        }
        
        public void export()
        {
            string path = Path.GetFullPath("company.txt");
            FileMode mode = FileMode.Create;
            if (File.Exists(path))
            {
                mode = FileMode.Append;
            }
            using (FileStream file = File.Open(path, mode, FileAccess.Write, FileShare.None))
            {
                string text =
                    $"name: {this.name}\nrating: {this.rating}\nworkers: {this.workers}\nincome: {this.income}\n";
                var info = new UTF8Encoding(true).GetBytes(text);
                file.Write(info, 0, info.Length);
            }
        }

        public void getNewWorkers(int students)
        {
            int newWorkers = Convert.ToInt32(students * 0.1);
            this.workers += newWorkers;
        }

        public class ITAccelerrator
        {
            private int projects;
            private int students;
            private double investing;

            public ITAccelerrator(int projects, int students, int investing)
            {
                this.projects = projects;
                this.students = students;
                this.investing = investing;
            }

            public void newStudents(int highRatingStudents)
            {
                this.students += highRatingStudents;
                
            }

            public void countInvesting()
            {
                Random random = new Random();
                int salary = random.Next(0, 10000);
                int materials = random.Next(0, 1000);
                int equipment = random.Next(0, 100);
                int electricity = random.Next(0, 500);
                int others = random.Next(0, 10000);
                this.investing = Convert.ToDouble(salary + materials + equipment + electricity + others) * 0.1;
            }
            
        }
    }
}