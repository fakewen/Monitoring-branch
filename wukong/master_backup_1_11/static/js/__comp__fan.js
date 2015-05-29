function Fan()
{
  Block.prototype.init.call(this);
  this.type='Fan';
  
    
      
        this.addAction( new Action('on_off'));
      
      
        this.addSignal( new Signal('on_off'));
      
    
  
}


Fan.prototype = new Block();
Fan.prototype.constructor = Fan;
Block.register('Fan', Fan);