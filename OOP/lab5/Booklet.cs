using System;

namespace lab5
{
    public class Booklet: PrintedEdition
    {
        public string CompanyName { get; set; }
        
        public Booklet() {}

        public Booklet(string companyName)
        {
            this.CompanyName = companyName;
        }

        public Booklet(string code, Booklet booklet)
        {
            if (code == "by keyboard")
            {
                Console.WriteLine("Enter the name of company which ad in booklet: ");
                CompanyName = Console.ReadLine();
            }
            else if (code == "copy" && booklet != null)
            {
                CompanyName = booklet.CompanyName;
                base.Title = booklet.Title;
                base.Cost = booklet.Cost;
                base.Language = booklet.Language;
                base.Purpose = booklet.Purpose;
            }
            else
            {
                throw new Exception("Invalid code!");
            }
        }
        
        
    }
}