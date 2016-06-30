function anda()
   t=timer;
   t.StartFcn = @initTimer;
   t.TimerFcn = @timerCallback;
   t.Period   = 0.1;
   t.TasksToExecute =200;
   t.ExecutionMode  = 'fixedRate';
%Rectangular room dimensions ;x->[0,room(1)], y-->[0,room(2)]
data=zeros(t.TasksToExecute,20);
room=[1.82 1.1]
% mydata = load('cali.mat');
% magx=mydata.magx;
% magy=mydata.magy;
i=1;
dt=t.Period;
x=zeros(3,1);
P=zeros(3,3);
u=1*[0.0;0.1];
qc_start_model('qbot2');
ok = qc_is_model_loaded('qbot2');
while(~ok)
    ok = qc_is_model_loaded('qbot2');
end
   pause(2);
   [mag,zIR]=check_angle();
   hardI=[-27.884615384615387 8.538461538461538];
   softI=[1.067765567765568 0.940322580645161];
   %mag=mag-repmat(hardI,length(mag),1);
   start(t);
   wait(t);
   delete(t);
set_param('qbot2/Qbot/V_r','value','0');
set_param('qbot2/Qbot/V_l','value','0');
qc_stop_model('qbot2')
save teste/giro270.mat data

   function initTimer(~,~)
        x(1)=random('Uniform',0,room(1),1);
        x(2)=random('Uniform',0,room(2),1);
        [z,H,h] = Hz(room,x,zIR');
        [x,~] = k_up(x,P,H,h,z);
        P= diag([10000,10000,3]);
        set_param('qbot2/Qbot/V_r','value',num2str(u(1)*1000));
        set_param('qbot2/Qbot/V_l','value',num2str(u(2)*1000));
        data(1,:)=[ 0 0 0 0 0 0 0 0 0 zIR mag(1) mag(2) 0 0 0 0];
        i=2;
        disp('initialised')
    end
 
    function timerCallback(~,~)
        u2 = read_encoder();
        [x,P]=k_pred(x,P,u,dt);
        % update
        [zIR,zSonar,zMag,IR_raw] = read_sensors();
        [z,H,h] = Hz(room,x,zIR);
        if (~isempty(z))
            [x,P] = k_up(x,P,H,h,z);
        end
        %circle2(x(1),x(2),room);
        %arrow(x,room);
        %grid on;
        data(i,:)=[u' u2' zIR' IR_raw' zMag' zSonar'];
        i=i+1;
    end
end
