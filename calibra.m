function calibra3()
   t=timer;
   t.StartFcn = @initTimer;
   t.TimerFcn = @timerCallback;
   t.Period   = 0.05;
   t.TasksToExecute =1000;
   t.ExecutionMode  = 'fixedRate';
   
   t1=timer;
   t1.StartFcn = @initTimer1;
   t1.TimerFcn = @timerCallback1;
   t1.Period   = 0.05;
   t1.TasksToExecute =101;
   t1.ExecutionMode  = 'fixedRate';
   
    a=zeros(t1.TasksToExecute,4);
    b=zeros(1,4);
dt=t.Period;
i=1;
u2=[0;0];
u=[0;0.1];
qc_start_model('qbot2');
ok = qc_is_model_loaded('qbot2');
while(~ok)
    ok = qc_is_model_loaded('qbot2');
end
   pause(2);
   start(t1);
   wait(t1);
   delete(t1);
   i=1;
   start(t);
   wait(t);
%    pause(2);
%    i=1;
%    u=[0;0.1];
%    start(t);
%    wait(t);
   delete(t);
set_param('qbot2/Qbot/V_r','value','0');
set_param('qbot2/Qbot/V_l','value','0');
qc_stop_model('qbot2')
mag_biasx= (max(b(:,2))+min(b(:,2)))/2;
mag_biasy= (max(b(:,3))+min(b(:,3)))/2;
mag_scalex=(max(b(:,2))-min(b(:,2)))/2;
mag_scaley=(max(b(:,3))-min(b(:,3)))/2;
avg=(mag_scalex+mag_scaley)/2;
mag_scalex=avg/mag_scalex;
mag_scaley=avg/mag_scaley;

save cali2.mat mag_biasx mag_biasy mag_scalex mag_scaley
b(:,6)=mod(b(:,1)*180/pi,360);
b(:,4)=(b(:,2)-mag_biasx)*mag_scalex;
b(:,5)=(b(:,3)-mag_biasy)*mag_scaley;
b(:,7)=mod(atan2(b(:,4),b(:,5))*180/pi,360);
save eu2.mat b


   function initTimer(~,~)
        disp('initialised')
        set_param('qbot2/Qbot/V_r','value',num2str(u(1)*1000));
        set_param('qbot2/Qbot/V_l','value',num2str(u(2)*1000));
    end
 
    function timerCallback(~,~)
%        if isempty(find(u>0.2 | u<-0.2, 1))
%            u2 = read_encoder();
%        else
            u2= u2 + [0;(dt*u(1)-dt*u(2))/0.27];
%        end
        disp(u2)
        disp(mod(u2(2)*180/pi,360))
       if u2(2)>=2*pi | u2(2)<=-2*pi 
            set_param('qbot2/Qbot/V_r','value','0');
            set_param('qbot2/Qbot/V_l','value','0');
            stop(t);
            disp('HAHA')
            [~,~,zMag,~] = read_sensors();
            b(i,:)=[u2(2) zMag'];

       end
        [~,~,zMag,~] = read_sensors();
        b(i,:)=[u2(2) zMag'];
        i=i+1;
    end
 function initTimer1(~,~)
        disp('initialised cal')
    end
 
    function timerCallback1(~,~)
    [~,~,zMag,~] = read_sensors();
    a(i,:)=[u(2) zMag'];
    i=i+1;
    end
end
