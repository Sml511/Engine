using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimalEditor.Utilities.UndoRedo
{
    public interface IUndoRedo
    {
        string Name { get; }
        void Undo();
        void Redo();






    }

    public class UndoRedoAction : IUndoRedo 
    {
        private Action _undoAction;
        private Action _redoAction;

        public string Name { get; }

        public void Redo() => _redoAction();
        public void Undo() => _undoAction();

        public UndoRedoAction(string name) 
        {
            Name = name;
            
        
        
        
        
        }
        public UndoRedoAction(Action undo, Action redo, string name):this(name) 
        {
            Debug.Assert(undo!=null&&redo!=null);
            _undoAction = undo;
            _redoAction = redo;

        
        
        
        
        }


        public UndoRedoAction(string property, object instance, object undoValue, object redoValue, string name) :

            this(

                () => instance.GetType().GetProperty(property).SetValue(instance, undoValue),
                () => instance.GetType().GetProperty(property).SetValue(instance, redoValue),

                name)
        { }
        
        
        
    
    
    
    }



    public class UndoRedo 
    {
        private bool _enabledAdd = true;
        private readonly ObservableCollection<IUndoRedo> _redoList = new ObservableCollection<IUndoRedo>();
        private readonly ObservableCollection<IUndoRedo> __undoList = new ObservableCollection<IUndoRedo>();
        public ReadOnlyObservableCollection<IUndoRedo> RedoList { get; }
        public ReadOnlyObservableCollection<IUndoRedo> UndoList { get; }
        public void Reset() 
        {
        
            _redoList.Clear();
            __undoList.Clear();
        
        
        }
        public void Add(IUndoRedo cmd) 
        {
            if (_enabledAdd)
            {

                __undoList.Add(cmd);
                _redoList.Clear();

            }
        
        
        
        }

        public void Undo() 
        {

            if (__undoList.Any()) 
            { 
                var cmd = __undoList.First();
                __undoList.RemoveAt(__undoList.Count - 1);
                _enabledAdd= false;
                cmd.Undo();
                _enabledAdd = true;
                _redoList.Insert(0, cmd);

            
            
            
            }
        
        
        
        
        
        }
        public void Redo() 
        {

            if (_redoList.Any()) 
            { 
                
                var cmd = _redoList.First();
                _redoList.RemoveAt(0);
                _enabledAdd= false;
                cmd.Redo();
                _enabledAdd = true;
                __undoList.Add(cmd);
                
            
            
            
            }
        
        
        
        }




        public UndoRedo() 
        {

            RedoList = new ReadOnlyObservableCollection<IUndoRedo>(_redoList);
            UndoList = new ReadOnlyObservableCollection<IUndoRedo>(__undoList);

        
        
        
        }


    
    
    }


}
