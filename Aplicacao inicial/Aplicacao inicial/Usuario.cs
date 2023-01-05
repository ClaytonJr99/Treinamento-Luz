using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aplicacao_inicial
{
    public class User : INotifyPropertyChanged
    {
        public int Id { get; set; }
        public string CPF { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }

        public User() { }


        public User(string Cpf, string Name, string Email, string Password, int Id)
        {
            this.CPF = Cpf;
            this.Id = Id;
            this.Name = Name;
            this.Email = Email;
            this.Password = Password;
        }


        public User Clone()
        {
            return (User)this.MemberwiseClone();
        }

        public event PropertyChangedEventHandler PropertyChanged;

        private void RaisePropertyChanged(string prop)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }

    }
}
