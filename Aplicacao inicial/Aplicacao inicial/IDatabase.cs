using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aplicacao_inicial
{
    public interface IDatabase
    {
        List<User> LoadList();
        void AddUser(User newUser);
        void EditUser(User user);
        void RemoveUser(User user);
    }
}
