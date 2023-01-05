using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace Aplicacao_inicial
{
    public class MainWindowsVM
    {
        public ObservableCollection<User> UsersList { get; set; }

        public ICommand Add { get; set; }

        public ICommand Remove { get; set; }

        public ICommand Edit { get; set; }

        public ICommand UpdateList { get; set; }


        public User SelectedUser { get; set; }

        private IDatabase connection { get; set; }

        // Construtor
        public MainWindowsVM()
        {
            connection = new MySql();
            ObservableCollection<User> DBList = new ObservableCollection<User>(connection.LoadList());
            UsersList = DBList;
            InitCommands();
        }

        public void InitCommands()
        {

            Add = new RelayCommand((object _) =>
            {
                User newUser = new User();

                CadastroUsuario screen = new CadastroUsuario();

                screen.DataContext = newUser;

                bool? verify = screen.ShowDialog();
                if (verify.HasValue && verify.Value)
                {
                    try
                    {
                        UsersList.Add(newUser);

                        connection.AddUser(newUser);

                    }
                    catch (Exception e)
                    {
                        MessageBox.Show($"Erro ao inserir {e.Message}");
                    }
                }

            });


            Edit = new RelayCommand((object _) =>
            {
                if (SelectedUser != null)
                {
                    User usuario = SelectedUser.Clone();

                    CadastroUsuario telaAtualizar = new CadastroUsuario();

                    telaAtualizar.DataContext = usuario;

                    bool? verifica = telaAtualizar.ShowDialog();

                    if (verifica.HasValue && verifica.Value)
                    {
                        try
                        {
                            SelectedUser.Name = usuario.Name;
                            SelectedUser.Email = usuario.Email;
                            SelectedUser.Password = usuario.Password;

                            connection.EditUser(SelectedUser);
                        }
                        catch (Exception e)
                        {
                            MessageBox.Show($"Erro ao editar {e.Message}");
                        }
                    }
                }
            }
            );

            Remove = new RelayCommand((object _) =>
            {
                User TempUser = SelectedUser;
                if (TempUser != null)
                {
                    try
                    {
                        UsersList.Remove(SelectedUser);
                        connection.RemoveUser(TempUser);
                    }
                    catch (Exception e)
                    {
                        MessageBox.Show($"Erro ao excluir {e.Message}");
                    }
                }

            });
            {

            };
        }
    }
}
