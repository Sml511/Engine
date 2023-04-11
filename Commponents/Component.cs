﻿using Microsoft.TeamFoundation.SourceControl.WebApi.Legacy;
using PrimalEditor.Common;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PrimalEditor.Commponents
{
    interface IMSComponent { }
    abstract class Component:ViewModelBase
    {

        public GameEntity Owner { get; private set; }

        public Component(GameEntity owner) 
        {

            Debug.Assert(owner != null);
            Owner = owner;

        
        }


    }

    abstract class MSComponent<T> : ViewModelBase, IMSComponent where T : Component { }


}
