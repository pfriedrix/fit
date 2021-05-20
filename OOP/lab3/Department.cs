using System;
using System.IO;
using System.Text;

namespace lab3
{
    public partial class Department
    {
        public string title;
        int lecturers;
        int students;
        int disciplines;
        int overall_time_disciplines;
        int awards;
        int invest_income;

        public int Lecturers
        {
            get => lecturers;
            set => lecturers = value;
        }

        public int Students
        {
            get => students;
            set => students = value;
        }

        public int Workers
        {
            get => students;
            set => students = value;
        }

        public int Disciplines
        {
            get => disciplines;
            set => disciplines = value;
        }

        public int Overall_time_disciplines
        {
            get => overall_time_disciplines;
            set => overall_time_disciplines = value;
        }

        public int Invest_income
        {
            get => invest_income;
            set => invest_income = value;
        }


        public Department()
        {
            this.title = "";
            this.lecturers = 0;
            this.students = 0;
            this.disciplines = 0;
            this.overall_time_disciplines = 0;
            this.awards = 0;
        }

        public Department(string title, int lecturers, int students, int disciplines, int overall_time_disciplines,
            int awards)
        {
            this.title = title;
            this.lecturers = lecturers;
            this.students = students;
            this.disciplines = disciplines;
            this.awards = awards;
            this.overall_time_disciplines = overall_time_disciplines;
        }

        public void increaseProgramLevel(int lecturers, int disciplines, int students)
        {
            this.lecturers += lecturers;
            this.disciplines += disciplines;
            this.students += students;
            Console.WriteLine("You successfully increase quality educational program");
        }
        

        public void export()
        {
            string path = Path.GetFullPath("department.txt");
            FileMode mode = FileMode.Create;
            if (File.Exists(path))
            {
                mode = FileMode.Append;
            }
            using (FileStream file = File.Open(path, mode, FileAccess.Write, FileShare.None))
            {
                string text =
                    $"title: {this.title}\nlecturers: {this.lecturers}\nstudents: {this.students}\ndisciplines: {this.disciplines}\nawards: {this.awards}\noverall time disciplines: {this.overall_time_disciplines}\n";
                var info = new UTF8Encoding(true).GetBytes(text);
                file.Write(info, 0, info.Length);
            }
        }
    }
}