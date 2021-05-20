using System;

namespace lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            Department inst = new Department();
            inst.title = "hello";
            inst.Students = 1000;
            inst.annualIncome();
            inst.increaseProgramLevel(10, 20, 30);
            inst.export();
            
            Company i = new Company();
            i.Name = "google";
            i.getNewWorkers(inst.Students);
            i.export();
            Company.ITAccelerrator comp = new Company.ITAccelerrator(10, 20, 40);
            comp.newStudents(10);
            comp.countInvesting();

            StartupProject project = new StartupProject();
            StartupProject.PrintOutMenu();
            StartupProject.CallByOption();
        }
        
    }
}