
using System;
using System.Linq;


namespace lab5
{
    public class PrintedEdition
    {
        private string title;
        private double cost;
        private string language;
        private string purpose;
        protected string[] purposes ={
            "science", "learning", "socio-political", "public"};

        public string Purpose
        {
            get => purpose;
            set
            {
                if (purposes.Contains(value)) purpose = value;
            }
        }

        public string Title
        {
            get => title;
            set => title = value;
        }

        public double Cost
        {
            get => cost;
            set => cost = value;
        }

        public string Language
        {
            get => language;
            set => language = value;
        }
    
        public PrintedEdition() {}
        public PrintedEdition(string title, double cost, string language, string purpose)
        {
            this.title = title;
            this.cost = cost;
            this.language = language;
            if (purposes.Contains(purpose)) this.purpose = purpose;
        }

        public PrintedEdition(string code, PrintedEdition? printedEdition = null)
        {
            if (code == "by keyboard")
            {
                Console.WriteLine("Enter the title this book: ");
                Title = Console.ReadLine();
                Console.WriteLine("Enter the cost this book: ");
                Cost = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the lang this book: ");
                Language = Console.ReadLine();
                Console.WriteLine("Enter the purpose this book: ");
                Purpose = Console.ReadLine();
            }
            else if (code == "copy" && printedEdition != null)
            {
                Title = printedEdition.Title;
                Cost = printedEdition.Cost;
                Language = printedEdition.Language;
                Purpose = printedEdition.Purpose;
            }
            else
            {
                throw new Exception("Invalid code!");
            }
        }

        public virtual void setCost()
        {
            
        }

        public virtual void setCirculation()
        {
            
        }
        
        PrintedEdition[] data;

        public void export()
        {
            Console.WriteLine("Title: " + title + " Cost: " + cost + " Lang: " + language);
        }

        public PrintedEdition this[int index]
        {
            get => data[index];
            set => data[index] = value;
        }
    }
}