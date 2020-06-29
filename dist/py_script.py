import AI_CORETEC_IF as nerv
import time
import threading
import struct
import signal
import sys

g_all_agent_sync = False

def signal_handler(sig, frame):
    print("signal_handler() called")
    print(flush = True)
    nerv.finalize()
    sys.exit(0)

class proxy_AI(nerv.proxy_coretec_scenario) :

    def connect_to_stub(self) :        
        self.AICarInformation_connect(True, 1.0, None)
        self.CausedObjectInformation_connect(True, 1.0, None)
        self.NpcCarInformation_connect(True, 1.0, None)
        self.StringInfoCommand_connect(1.0, None)
        self.TickInformation_connect(True, 1.0, None)
        self.TrafficLightInformation_connect(True, 1.0, None)

        # 2018.12.21 추가
        self.SpawnCommand_connect(1.0, None)
        self.ControlInfoCommand_connect(1.0, None)
        self.NpcAnimalInformation_connect(True, 1.0, None)
        self.NpcHumanInformation_connect(True, 1.0, None)
        self.NpcOtherObjectInformation_connect(True, 1.0, None)

        # 2018.11.19 추가
        self.AIVehicleControlCommand_connect(1.0, None)

        # 2018.11.26 추가
        self.CrashInformation_connect(True, 1.0, None)
        self.SystemSettingInformation_connect(True, 1.0, None)
        self.TimeStampInformation_connect(True, 1.0, None)
        self.AllAgentsInformation_connect(True, 1.0, None)

        # 2019.01.24 추가
        self.EnvObjStatusInformation_connect(True, 1.0, None)    
        self.ScenarioSettingInformation_connect(True, 1.0, None)
        self.WeatherStatusInformation_connect(True, 1.0, None)
        self.ScenarioFrequencyInformation_connect(True, 1.0, None)
        self.ScenarioControlInformation_connect(True, 1.0, None)
        self.EventInformation_connect(True, 1.0, None)
        self.ScenarioSignalInformation_connect(True, 1.0, None)
        self.ObjectControlInformation_connect(True, 1.0, None)
        self.TrafficLightControlInformation_connect(True, 1.0, None)
        self.AnimalControlCommand_connect(1.0, None)
        self.AnimalSpawnCommand_connect(1.0, None)
        self.HumanControlCommand_connect(1.0, None)
        self.HumanSpawnCommand_connect(1.0, None)
        self.TrafficLightControlCommand_connect(1.0, None)
        self.VehicleControlCommand_connect(1.0, None)
        self.VehicleSpawnCommand_connect(1.0, None)    
        self.AutomaticEventInformation_connect(1.0, None)
        self.DeactivEventInformation_connect(1.0, None)
        self.WeatherControlInformation_connect( 1.0, None)
        self.EnvObjSpawnInformation_connect(1.0, None)    
        self.EnvObjControlInformation_connect( 1.0, None)
        self.DeleteObjectInformation_connect( 1.0, None)   

    def on_object_create(self) :
        print("py::on_object_create()")         
        print(flush = True)
        self.connect_to_stub()

    def on_object_destroy(self) :
        print("py::on_object_destroy()")
        print(flush = True)
    
    # information : AICarInformation
    def on_AICarInformation_disconnected(self) :
        print("py::on_AICarInformation_disconnected()")
        print(flush = True)

    def on_AICarInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_AICarInformation_sync()")
        print("Yaw :" + str(pin_buffer.Yaw))
        print("posX :" + str(pin_buffer.posX))
        print("posY :" + str(pin_buffer.posY))
        print("posZ :" + str(pin_buffer.posZ))
        print("CarAccellValue :" + str(pin_buffer.CarAccellValue))
        print(flush = True)

    # information : NpcCarInformation
    def on_NpcCarInformation_disconnected(self) :
        print("py::on_NpcCarInformation_disconnected()")
        print(flush = True)

    def on_NpcCarInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_NpcCarInformation_sync()")
        print("NpcCarID :" + str(pin_buffer.NpcCarID))
        print("AnimationInfo[0].PartID :" + str(pin_buffer.AnimationInfo[0].PartID))
        print("AnimationInfo[0].AnimationPlaySpeed :" + str(pin_buffer.AnimationInfo[0].AnimationPlaySpeed))
        print("AnimationInfo[0].AnimationPlayWidth :" + str(pin_buffer.AnimationInfo[0].AnimationPlayWidth))
        print("AnimationInfo[0].AnimationLoop :" + str(pin_buffer.AnimationInfo[0].AnimationLoop))
        print("AnimationInfo[1].PartID :" + str(pin_buffer.AnimationInfo[1].PartID))
        print("AnimationInfo[1].AnimationPlaySpeed :" + str(pin_buffer.AnimationInfo[1].AnimationPlaySpeed))
        print("AnimationInfo[1].AnimationPlayWidth :" + str(pin_buffer.AnimationInfo[1].AnimationPlayWidth))
        print("AnimationInfo[1].AnimationLoop :" + str(pin_buffer.AnimationInfo[1].AnimationLoop))
        print(flush = True)

    # information : TrafficLightInformation
    def on_TrafficLightInformation_disconnected(self) :
        print("py::on_TrafficLightInformation_disconnected()")
        print(flush = True)

    def on_TrafficLightInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_TrafficLightInformation_sync()")
        print("TrafficLightID :" + str(pin_buffer.TrafficLightID))
        print("TrafficLocation[0] :" + str(pin_buffer.TrafficLocation[0]))
        print("TrafficLocation[1] :" + str(pin_buffer.TrafficLocation[1]))
        print("TrafficLocation[2] :" + str(pin_buffer.TrafficLocation[2]))
        print(flush = True)




    # information : GameEngineInformation
    def on_GameEngineInformation_disconnected(self) :
        print("py::on_GameEngineInformation_disconnected()")
        print(flush = True)

    def on_GameEngineInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_GameEngineInformation_sync()")
        print("FPS :" + str(pin_buffer.FPS))
        print("MAX_CAR_NUM :" + str(pin_buffer.MAX_CAR_NUM))
        print(flush = True)

    # information : TickInformation
    def on_TickInformation_disconnected(self) :
        print("py::on_TickInformation_disconnected()")
        print(flush = True)

    def on_TickInformation_sync(self, in_sync_model, in_elapsed, in_limit, in_buffer) :
        print("py::on_TickInformation_sync()")
        print("Tick :" + str(in_buffer))
        print(flush = True)

    # information : CausedObjectInformation
    def on_CausedObjectInformation_disconnected(self) :
        print("py::on_CausedObjectInformation_disconnected()")
        print(flush = True)

    def on_CausedObjectInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_CausedObjectInformation_sync()")
        print("CauseObjectID :" + pin_buffer.CauseObjectID)
        print("CausedObjectID :" + pin_buffer.CausedObjectID)
        print("Impulse :" + str(pin_buffer.Impulse))
        print(flush = True)

    # information : NpcAnimalInformation
    def on_NpcAnimalInformation_disconnected(self) :
        print("py::on_CausedObjectInformation_disconnected()")
        print(flush = True)

    def on_NpcAnimalInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_NpcAnimalInformation_sync()")
        print("NpcAnimalID :" + pin_buffer.NpcAnimalID)
        print("TODO : print more member data")
        print(flush = True)    

    # information : NpcHumanInformation
    def on_NpcHumanInformation_disconnected(self) :
        print("py::on_NpcHumanInformation_disconnected()")
        print(flush = True)

    def on_NpcHumanInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_NpcHumanInformation_sync()")
        print("NpcHumanID :" + pin_buffer.NpcHumanID)
        print("TODO : print more member data")
        print(flush = True)

    # information : NpcOtherObjectInformation
    def on_NpcOtherObjectInformation_disconnected(self) :
        print("py::on_NpcOtherObjectInformation_disconnected()")
        print(flush = True)

    def on_NpcOtherObjectInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_NpcOtherObjectInformation_sync()")
        print("NpcOtherObjectID :" + pin_buffer.NpcOtherObjectID)
        print("TODO : print more member data")
        print(flush = True)

    # information : CrashInformation
    def on_CrashInformation_disconnected(self) :
        print("py::on_CrashInformation_disconnected()")
        print(flush = True)

    def on_CrashInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_CrashInformation_sync()")
        print("CausedObjectDamagedPartList[0] :" + str(pin_buffer.CausedObjectDamagedPartList[0]))
        print("TODO : print more member data")
        print(flush = True)
    
    # information : SystemSettingInformation
    def on_SystemSettingInformation_disconnected(self) :
        print("py::on_SystemSettingInformation_disconnected()")
        print(flush = True)

    def on_SystemSettingInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_SystemSettingInformation_sync()")
        print("FPS :" + str(pin_buffer.FPS))
        print("TODO : print more member data")
        print(flush = True)

    # information : TimeStampInformation
    def on_TimeStampInformation_disconnected(self) :
        print("py::on_TimeStampInformation_disconnected()")
        print(flush = True)

    def on_TimeStampInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_TimeStampInformation_sync()")
        print("Minutes :" + str(pin_buffer.Minutes))
        print("TODO : print more member data")
        print(flush = True)

    # information : AllAgentsInformation
    def on_AllAgentsInformation_disconnected(self) :
        print("py::on_AllAgentsInformation_disconnected()")
        print(flush = True)

    def on_AllAgentsInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        global g_all_agent_sync
        g_all_agent_sync = True
        print("py::on_AllAgentsInformation_sync()")        
        # print("HumanStatus[0].NpcHumanID :" + pin_buffer.HumanStatus[0].NpcHumanID)
        # print("TimeStatus.Minutes :" + str(pin_buffer.TimeStatus.Minutes))
        # print("TODO : print more member data")

        print(flush = True)

    # command : VehicleCommand
    def on_VehicleSpawnCommand_disconnected(self) :
        print("py::on_VehicleSpawnCommand_disconnected()")
        print(flush = True)

    # command : TrafficLightControlCommand
    def on_TrafficLightControlCommand_disconnected(self) :
        print("py::on_TrafficLightControlCommand_disconnected()")
        print(flush = True)

    # command : VehicleControlCommand
    def on_VehicleControlCommand_disconnected(self) :
        print("py::on_VehicleControlCommand_disconnected()")
        print(flush = True)

    # command : StringInfoCommand
    def on_StringInfoCommand_disconnected(self) :
        print("py::on_StringInfoCommand_disconnected()")
        print(flush = True)

    # command : AnimalControlCommand
    def on_AnimalControlCommand_disconnected(self) :
        print("py::on_AnimalControlCommand_disconnected()")
        print(flush = True)

    # command : AnimalSpawnCommand
    def on_AnimalSpawnCommand_disconnected(self) :
        print("py::on_AnimalSpawnCommand_disconnected()")
        print(flush = True)

    # command : HumanControlCommand
    def on_HumanControlCommand_disconnected(self) :
        print("py::on_HumanControlCommand_disconnected()")
        print(flush = True)

    # command : HumanSpawnCommand
    def on_HumanSpawnCommand_disconnected(self) :
        print("py::on_HumanSpawnCommand_disconnected()")
        print(flush = True)

    def on_EnvObjStatusInformation_sync(self) :
        print("py::on_EnvObjStatusInformation_sync()")
        print(flush = True)

    def on_EventInformation_sync(self) :
        print("py::on_EventInformation_sync()")
        print(flush = True)

    def on_ObjectControlInformation_sync(self) :
        print("py::on_ObjectControlInformation_sync()")
        print(flush = True)        

    def on_ScenarioControlInformation_sync(self) :
        print("py::on_ScenarioControlInformation_sync()")
        print(flush = True)

    def on_ScenarioSettingInformation_sync(self) :
        print("py::on_ScenarioSettingInformation_sync()")
        print(flush = True)

    def on_ScenarioSignalInformation_sync(self) :
        print("py::on_ScenarioSignalInformation_sync()")
        print(flush = True)

    def on_TimeStampInformation_sync(self) :
        print("py::on_TimeStampInformation_sync()")
        print(flush = True)

    def on_TrafficLightControlInformation_sync(self) :
        print("py::on_TrafficLightControlInformation_sync()")
        print(flush = True)

    def on_WeatherStatusInformation_sync(self) :
        print("py::on_WeatherStatusInformation_sync()")
        print(flush = True)

    # 가변 버퍼 필드를 적재할 리스트
    def __init__(self) :
        print("init")
        self.spawn_human_list = []
        self.spawn_animal_list = []
        self.spawn_vehicle_list = []
        self.spawn_envobj_list = []

        # 부모 클래스 생성자 호출
        nerv.proxy_coretec_scenario.__init__(self)

    # spawn human 데이터 적재
    def spawn_human_append(self, human_info) :
        self.spawn_human_list.append(human_info)
    
    # spawn animal 데이터 적재
    def spawn_animal_append(self, animal_info) :
        self.spawn_animal_list.append(animal_info)
    
    def spawn_vehicle_append(self, vehicle_info) :
        self.spawn_vehicle_list.append(vehicle_info)
    
    def spawn_envobj_append(self, envobj_info) :
        self.spawn_envobj_list.append(envobj_info)

    # spawn 적재된 데이터 전송
    def send_spawn_all(self) :

        print("py::send_spawn_all()")
        print(flush = True)
        
        # 가변버퍼 초기화
        Spawn_Info = self.SpawnCommand_get()
        Spawn_Info.init_dynamic_buffer()

        # human 필드 크기 할당 및 값 설정
        human_list_size = len(self.spawn_human_list)
        Spawn_Info.human_spawn_alloc(human_list_size)
        
        for i in range(human_list_size) :
            human = Spawn_Info.human_spawn(i)
            human.HumanID = self.spawn_human_list[i].HumanID
        
        # animal 필드 크기 할당 및 값 설정
        animal_list_size = len(self.spawn_animal_list)
        Spawn_Info.animal_spawn_alloc(animal_list_size)

        for i in range(animal_list_size) :
            animal = Spawn_Info.animal_spawn(i)
            animal.AnimalID = self.spawn_animal_list[i].AnimalID

        # vehicle 필드 크기 할당 및 값 설정
        vehicle_list_size = len(self.spawn_vehicle_list)
        Spawn_Info.vehicle_spawn_alloc(vehicle_list_size)

        for i in range(vehicle_list_size) :
            vehicle = Spawn_Info.vehicle_spawn(i)
            vehicle.VehicleID = self.spawn_vehicle_list[i].VehicleID

        # envobj 필드 크기 할당 및 값 설정
        envobj_list_size = len(self.spawn_envobj_list)
        Spawn_Info.envobj_spawn_alloc(envobj_list_size)

        for i in range(envobj_list_size) :
            envobj = Spawn_Info.envobj_spawn(i)
            envobj.EnvObjID = self.spawn_envobj_list[i].EnvObjID

        self.SpawnCommand_post(Spawn_Info)

        self.spawn_animal_list.clear()
        self.spawn_human_list.clear()
        self.spawn_vehicle_list.clear()
        self.spawn_envobj_list.clear()


    def send_total(self) :
        # 미들웨어 로부터 전송 버퍼 할당 받아 획득합니다.
        Control_Info = self.ControlInfoCommand_get()
        
        # 할당받은 버퍼는 가변필드가 있는 구조 데이터이므로 가변버퍼를 초기화 합니다.
        Control_Info.init_dynamic_buffer()

        # 첫번째 가변필드 human_objects의 갯수만큼 할당합니다.
        Control_Info.human_objects_alloc(10)
        
        # human_objects의 배열을 작성합니다.
        i = 0
        while i<10:
            human = Control_Info.human_objects(i)
            human.Speed[0] = 1
            human.Speed[1] = 2
            human.HumanID = "002"
            i=i+1

        print("8")
        print(flush = True)
         
        Control_Info.animal_objects_alloc(20)
        i = 0
        while i<20:   
            print("9")
            print(flush = True)
            animal = Control_Info.animal_objects(i)
            animal.Speed[0] = 1
            animal.Speed[1] = 2
            animal.AnimalID = "003"
            i = i+1

        Control_Info.vehicle_objects_alloc(30)

        print(flush = True)

        ani_info = nerv.AnimationInfo()
        ani_info.PartID = 1
        ani_info.AnimationID = 13
        ani_info.AnimationLoop = 1
        ani_info.AnimationPlaySpeed = 13.3
        ani_info.AnimationPlayWidth = 31.9
        
        i = 0
        while i< 30 :
            print(flush = True)
            vci = Control_Info.vehicle_objects(i)
            vci.VehicleID = "001"
            vci.Direction[0] = 1.1
            vci.Direction[1] = 2.2
            vci.Destination[0] = 1.1
            vci.Destination[1] = 2.2

            vci.AnimationInfo[0] = ani_info

            i=i+1

        Control_Info.traffic_light_objects_alloc(40)
        i = 0
        while i<40:  
            tlight = Control_Info.traffic_light_objects(i)
            tlight.TrafficLightID = "004"
            i = i+1

        Control_Info.envobj_objects_alloc(0)

        # 작성한 가변필드가 있는 구조데이터를 post하여 실제 전송이 발생하도록 합니다.
        self.ControlInfoCommand_post(Control_Info)

    def send_automatic_event_list(self) :
        automatic_event_info = self.AutomaticEventInformation_get()
        automatic_event_info.init_dynamic_buffer()
        automatic_event_info.AutomaticEventList_alloc(10)

        i = 0
        while i<10:
            event_info = automatic_event_info.AutomaticEventList(i)
            event_info.EventType = i
            event_info.SequenceInfoListSize = 2
            
            event_info.SequenceInfoList[0].ObjectType = i
            event_info.SequenceInfoList[1].ObjectType = i+1
            
            event_info.SequenceInfoList[0].ActionInfoListSize = 3            
            event_info.SequenceInfoList[0].ActionInfoList[0].ActionType = i
            event_info.SequenceInfoList[0].ActionInfoList[1].ActionType = i+1
            event_info.SequenceInfoList[0].ActionInfoList[2].ActionType = i+2
            
            event_info.SequenceInfoList[1].ActionInfoListSize = 0

            i=i+1
        
        self.AutomaticEventInformation_post(automatic_event_info)

def nerv_init() :

    nerv.initialize()

    print("nerv_init() start")    

    while True :
        nerv.dispatch_msg(0)
        time.sleep(0.001)
    
    nerv.finalize()
    print("nerv_init() end")

def main() :    
    nerv_thread = threading.Thread(target=nerv_init)    

    nerv_thread.daemon = True
    nerv_thread.start()    
    
    proxy_obj = proxy_AI()
    stub_obj_id = 1
    print(nerv.const.c_AI_port)
    proxy_obj.create(nerv.const.c_AI_port, nerv.inet_addr("127.0.0.1"), stub_obj_id, 0)    

    vehicle_spawn_info = nerv.VehicleSpawnInfo()
    vehicle_spawn_info.Location[0] = 7
    vehicle_spawn_info.Location[1] = 8
    vehicle_spawn_info.Rotation[0] = 3
    vehicle_spawn_info.Rotation[1] = 1
    vehicle_spawn_info.VehicleID = "001"
    vehicle_spawn_info.AnimationInfoSize = 2    

    ani_info = nerv.AnimationInfo()
    ani_info.PartID = 1
    ani_info.AnimationID = 13
    ani_info.AnimationLoop = 1
    ani_info.AnimationPlaySpeed = 13.3
    ani_info.AnimationPlayWidth = 31.9
    vehicle_spawn_info.AnimationInfo[0] = ani_info

    ani_info.PartID = 2
    ani_info.AnimationID = 14
    ani_info.AnimationLoop = 0
    ani_info.AnimationPlaySpeed = 23.3
    ani_info.AnimationPlayWidth = 41.9
    vehicle_spawn_info.AnimationInfo[1] = ani_info

    traffic_light_control_info = nerv.TrafficLightControlInfo()
    traffic_light_control_info.TrafficLightID = "0001"
    #traffic_light_control_info.set_isPhysicalEffect(chr(1)) #isPhysicalEffect[0] = 1
    #traffic_light_control_info.set_isPhysicalEffect(chr(0)) #isPhysicalEffect[1] = 0
    traffic_light_control_info.isPhysicalEffect = 0
    traffic_light_control_info.ActionType = 3        

    vehicle_control_info = nerv.VehicleControlInfo()
    vehicle_control_info.VehicleID = "007"
    vehicle_control_info.Direction[0] = 7.1 #Direction[0] = 7
    vehicle_control_info.Direction[1] = 9.3 #Direction[1] = 9

    vehicle_control_info.Destination[0] = 3.3
    vehicle_control_info.Destination[1] = 6.6
    vehicle_control_info.Destination[2] = 9.9

    string_info = nerv.StringInfo()    
    string_info.data = "str_info"    

    # 2018.11.15 추가
    animal_control_info = nerv.AnimalControlInfo()
    animal_control_info.AnimalID = "100"

    animal_spawn_info = nerv.AnimalSpawnInfo()
    animal_spawn_info.AnimalID = "101"

    human_control_info = nerv.HumanControlInfo()
    human_control_info.HumanID = "200"

    human_spawn_info = nerv.HumanSpawnInfo()
    human_spawn_info.HumanID = "201"

    # 1018.11.19 추가
    ai_vehicle_control_info = nerv.AIVehicleControlInfo()
    ai_vehicle_control_info.VehicleID = "119"

    envobj_spawn_info = nerv.EnvObjSpawnInfo()
    envobj_spawn_info.EnvObjID = "404"

    deactive_event_info = nerv.DeactiveEventInfo()
    deactive_event_info.set_DeactiveEventList(0, "event1")
    deactive_event_info.set_DeactiveEventList(1, "event2")
    deactive_event_info.set_DeactiveEventList(2, "event3")
    deactive_event_info.DeactiveEventCount = 3

    # main_loop
    loop_cnt = 0
    while True:
        loop_cnt += 1
        #print(loop_cnt, flush = True) # main thread 살아있는지 확인이 필요할 때 사용
        time.sleep(1)

        proxy_obj.DeactivEventInformation_write(deactive_event_info)

        #proxy_obj.send_total()
        
        # send_spawn_all 사용법 테스트
        proxy_obj.spawn_human_append(human_spawn_info)
        proxy_obj.spawn_animal_append(animal_spawn_info)
        proxy_obj.spawn_vehicle_append(vehicle_spawn_info)
        proxy_obj.spawn_envobj_append(envobj_spawn_info)
                
        if loop_cnt % 10 == 0 :
            proxy_obj.send_spawn_all()
        
        if g_all_agent_sync == True:     
            all_agent_info = nerv.AllAgentsInformation()
            proxy_obj.AllAgentsInformation_read(all_agent_info) # 가장 최근 on_sync로 수신한 데이터 얻기
            print("all_agent_info read: " + str(all_agent_info.AutomaticCarStatusMemory.posX))                    
        
        proxy_obj.send_automatic_event_list()

# main() 함수        
if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal_handler)
    main()
    