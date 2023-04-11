using PrimalEditor.Commponents;
using PrimalEditor.GameProject;
using PrimalEditor.Utilities.UndoRedo;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace PrimalEditor.Editors.WorldEditor
{
    /// <summary>
    /// ProjectLayoutView.xaml 的交互逻辑
    /// </summary>
    public partial class ProjectLayoutView : UserControl
    {
        public ProjectLayoutView()
        {
            InitializeComponent();
        }

        private void OnAddGameEntity_Button_Click(object sender,RoutedEventArgs e) 
        {

            var bin = sender as Button;
            var vm = bin.DataContext as Scene;
            vm.AddGameEntityCommand.Execute(new GameEntity(vm) { Name = "Empty Game Entity" });



        
        
        }

        private void Button_Click(object sender, RoutedEventArgs e) 
        {

            var vm = DataContext as Project;
            vm.AddScene("New Scene"+vm.Scenes.Count);

        
        }

        private void OnGameEntities_ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e) 
        {
            GameEntityView.Instance.DataContext = null;
            var listBox = sender as ListBox;
            //if (e.AddedItems.Count > 0) 
            //{
              //  GameEntityView.Instance.DataContext = (sender as ListBox).SelectedItems[0];
            
            
            
            //}

          
            var newSelection = listBox.SelectedItems.Cast<GameEntity>().ToList();
            var previousSelection = newSelection.Except(e.AddedItems.Cast<GameEntity>()).Concat(e.RemovedItems.Cast<GameEntity>()).ToList();

            Project.UndoRedo.Add(new UndoRedoAction(
                ()=> // Undo action
                {
                    listBox.UnselectAll();
                    previousSelection.ForEach(x=>(listBox.ItemContainerGenerator.ContainerFromItem(x) as ListBoxItem).IsSelected = true);
                },
                ()=> // redo action 
                {
                    listBox.UnselectAll();
                    newSelection.ForEach(x => (listBox.ItemContainerGenerator.ContainerFromItem(x) as ListBoxItem).IsSelected = true);


                },
                "Selected Action"
                
                
                ));

            MSGameEntity msEntity = null;
            if (newSelection.Any()) 
            {

                msEntity = new MSGameEntity(newSelection);
            
            
            
            
            }

            GameEntityView.Instance.DataContext = msEntity;
        
        
        }
    }
}
