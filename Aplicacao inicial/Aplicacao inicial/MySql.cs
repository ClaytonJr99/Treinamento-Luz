using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;

namespace Aplicacao_inicial
{
    public class MySql : IDatabase
    {
        private readonly string connectionString = "SERVER=localhost;DATABASE=usuarios;UID=root;PASSWORD=password";
        
        private MySqlConnection GetConnection()
        {
            return new MySqlConnection(connectionString);
        }

        public List<User> LoadList()
        {
            try
            {
                using (MySqlConnection con = GetConnection())
                {
                    List<User> list = new List<User>();
                    string query = "select * from usuarios";
                    MySqlCommand cmd = new MySqlCommand(query, con);
                    con.Open();
                    MySqlDataReader reader= cmd.ExecuteReader();
                    while (reader.Read())
                    {
                        User user = new User()
                        {
                            Id = reader.GetInt32(0),
                            Name = reader.GetString(1),
                            Email = reader.GetString(2),
                            Password = reader.GetString(3),
                        };
                        list.Add(user);
                    }
                    con.Close();
                    return list;
                }
            }
            catch (Exception e)
            {
                throw e;
            }

        }
        public void AddUser(User user)
        {
            try
            {
                using (MySqlConnection con = GetConnection())
                {
                    string query = $@"insert into usuarios(name, email, Password) values ('{user.Name}', '{user.Email}', '{user.Password}')";
                    MySqlCommand cmd = new MySqlCommand(query, con);
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            catch(Exception e)
            {
                throw e;
            }
        }

        public void EditUser(User user)
        {
            try
            {
                using(MySqlConnection con = GetConnection())
                {
                    string query = $@"update usuarios set name='{user.Name}', email='{user.Email}', Password='{user.Password}' where id='{user.Id}'";
                    MySqlCommand cmd = new MySqlCommand(query, con);
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            catch(Exception e)
            {
                throw e;
            }
        }

        public void RemoveUser(User user) 
        { 
            try
            {
                using (MySqlConnection con = GetConnection())
                {
                    string query = $@"delete from usuarios where id='{user.Id}'";
                    MySqlCommand cmd = new MySqlCommand(query, con);
                    con.Open();
                    cmd.ExecuteNonQuery();
                    con.Close();
                }
            }
            catch(Exception e)
            {
                throw e;
            }
        }

    }
}
