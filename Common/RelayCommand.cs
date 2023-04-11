using System;
using System.CodeDom.Compiler;
using System.Windows.Input;

namespace PrimalEditor.Common
{


    public class RelayCommand<T> : ICommand
    {
       
        private readonly Action<T> _execute;
        private readonly Predicate<T> _canExecute;

        private event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value;}

        
        
        
        
        }

        event EventHandler? ICommand.CanExecuteChanged
        {
            add
            {
                throw new NotImplementedException();
            }

            remove
            {
                throw new NotImplementedException();
            }
        }

        private bool CanExecute(object parameter) 
        {

            return _canExecute?.Invoke((T)parameter) ?? true;
             
        
        }
        private void Execute(object parameter) 
        {

            _execute((T)parameter);
        
        
        
        }

        bool ICommand.CanExecute(object? parameter)
        {
            throw new NotImplementedException();
        }

        void ICommand.Execute(object? parameter)
        {
            throw new NotImplementedException();
        }

        public RelayCommand(Action<T> execute,Predicate<T> canExecute = null) 
        { 
            
        
            _execute = execute ?? throw new ArgumentNullException(nameof(execute));
            _canExecute = canExecute;
        
        
        
        }
    
    
    }

}
