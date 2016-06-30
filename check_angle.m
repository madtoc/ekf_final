function [mag,IR] = check_angle()
   t=timer;
   t.StartFcn = @initTimer;
   t.TimerFcn = @timerCallback;
   t.Period   = 0.05;
   t.TasksToExecute =100;
   t.ExecutionMode  = 'fixedRate';
   temp=zeros(t.TasksToExecute,7);
   i=1;
   start(t);
   wait(t);
   delete(t);
   temp=mean(temp);
   mag=temp(1:2);
   IR=temp(3:end);
   function initTimer(~,~)
        disp('initialised')
    end
 
    function timerCallback(~,~)
    [~,~,zMag,IR_raw] = read_sensors();
    temp(i,:)=[zMag(1:2)' IR_raw'];
    i=i+1;
    end
end
