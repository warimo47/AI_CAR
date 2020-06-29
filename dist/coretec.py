import AI_CORETEC_IF as nerv
import time
import threading
import struct
import signal
import sys

global proxy_obj

global Total_Npc_Count
global Total_Human_ID_Count
global Total_Animal_ID_Count
global Total_Vehicle_ID_Count

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
##        print("py::on_object_create()")         
        print(flush = True)
        self.connect_to_stub()

    def on_object_destroy(self) :
        print("py::on_object_destroy()")
        print(flush = True)

    # information : AICarInformation
    def on_AICarInformation_disconnected(self) :
        print(flush = True)

    def on_AICarInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.AICarInfo = pin_buffer

    # information : NpcCarInformation
    def on_NpcCarInformation_disconnected(self) :
        print(flush = True)

    def on_NpcCarInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.NpcCar = pin_buffer

    # information : TrafficLightInformation
    def on_TrafficLightInformation_disconnected(self) :
        print(flush = True)

    def on_TrafficLightInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.NpcTraffic = pin_buffer

    # information : GameEngineInformation
    def on_GameEngineInformation_disconnected(self) :
        print(flush = True)

    def on_GameEngineInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.GameSetting = pin_buffer

    # information : TickInformation
    def on_TickInformation_disconnected(self) :
        print("py::on_TickInformation_disconnected()")

    def on_TickInformation_sync(self, in_sync_model, in_elapsed, in_limit, in_buffer) :
        self.Tick = in_buffer

    # information : CausedObjectInformation
    def on_CausedObjectInformation_disconnected(self) :
        print(flush = True)

    def on_CausedObjectInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.CausedObject = pin_buffer

    # information : NpcAnimalInformation
    def on_NpcAnimalInformation_disconnected(self) :
        print(flush = True)

    def on_NpcAnimalInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.NpcAnimal = pin_buffer

    # information : NpcHumanInformation
    def on_NpcHumanInformation_disconnected(self) :
        print(flush = True)

    def on_NpcHumanInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.NpcHuman = pin_buffer

    # information : NpcOtherObjectInformation
    def on_NpcOtherObjectInformation_disconnected(self) :
        print(flush = True)

    def on_NpcOtherObjectInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_NpcOtherObjectInformation_sync()")

    # information : CrashInformation
    def on_CrashInformation_disconnected(self) :
        print(flush = True)

    def on_CrashInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.CrashInfo = pin_buffer

    # information : SystemSettingInformation
    def on_SystemSettingInformation_disconnected(self) :
        print(flush = True)

    def on_SystemSettingInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.SystemSettingInfo = pin_buffer

    # information : TimeStampInformation
    def on_TimeStampInformation_disconnected(self) :
        print("py::on_TimeStampInformation_disconnected()")
        print(flush = True)

    def on_TimeStampInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.TimeStamp = pin_buffer

    # information : AllAgentsInformation
    def on_AllAgentsInformation_disconnected(self) :
        print(flush = True)

    def on_AllAgentsInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.Agent = pin_buffer
        print("py::on_AllAgentsInformation_sync()")
        print(flush = True)
        current_location = [ self.Agent.HumanStatusMemory[0].NpcHumanLocation[0],
                             self.Agent.HumanStatusMemory[0].NpcHumanLocation[1],
                             self.Agent.HumanStatusMemory[0].NpcHumanLocation[2]]

    # AutomaticEventInfomationList 보내는 예시 함수
    def Send_AutomaticEventInfoList(self) :
        AutomaticEventInfo = self.AutomaticEventInformation_get()
        AutomaticEventInfo.init_dynamic_buffer()

        AutomaticEventInfoNum = 2
        
        AutomaticEventInfo.AutomaticEventList_alloc(AutomaticEventInfoNum)
        
        AEI_Count = 0
        while AEI_Count < AutomaticEventInfoNum :
            TargetEventInformation = AutomaticEventInfo.AutomaticEventList(AEI_Count)
            TargetEventInformation.EventID = "%d" %AEI_Count
            TargetEventInformation.EventPosition[0] = 7000 + AEI_Count * 500
            TargetEventInformation.EventPosition[1] = 7000
            TargetEventInformation.EventPosition[2] = 0
            TargetEventInformation.EventType = 0
            TargetEventInformation.ObjectType = 0
            TargetEventInformation.ObjectResourceType = 0
            TargetEventInformation.AutomaticEventType = 0
            TargetEventInformation.SequenceInfoListSize = 2

            SI_Count = 0
            while SI_Count < TargetEventInformation.SequenceInfoListSize :
                TargetEventInformation.SequenceInfoList[SI_Count].ObjectType = 0
                TargetEventInformation.SequenceInfoList[SI_Count].ObjectResourceType = 0
                TargetEventInformation.SequenceInfoList[SI_Count].GeneratePosition[0] = 7000 + AEI_Count * 500
                TargetEventInformation.SequenceInfoList[SI_Count].GeneratePosition[1] = 7010 + SI_Count * 50
                TargetEventInformation.SequenceInfoList[SI_Count].GeneratePosition[2] = 150
                TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoListSize = 2

                AI_Count = 0
                while AI_Count < TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoListSize :
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].StartSequenceIndex = 0
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].EndSequenceIndex = 0
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].PositionType = 0
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].Position[0] = 7000 + AEI_Count * 500 + AI_Count * 10
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].Position[1] = 7010 + SI_Count * 50
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].Position[2] = 150
                    TargetEventInformation.SequenceInfoList[SI_Count].ActionInfoList[AI_Count].ActionType = 0
                    AI_Count = AI_Count + 1
                    
                SI_Count = SI_Count + 1
                
            AEI_Count = AEI_Count + 1
        
        self.AutomaticEventInformation_post(AutomaticEventInfo)
        print("py::Send_AutomaticEventInfoList()\n")

    # disconneted 함수
    def on_VehicleSpawnCommand_disconnected(self) :
        print("py::on_VehicleSpawnCommand_disconnected()")
        print(flush = True)

    def on_TrafficLightControlCommand_disconnected(self) :
        print("py::on_TrafficLightControlCommand_disconnected()")
        print(flush = True)

    def on_VehicleControlCommand_disconnected(self) :
        print("py::on_VehicleControlCommand_disconnected()")
        print(flush = True)

    def on_StringInfoCommand_disconnected(self) :
        print("py::on_StringInfoCommand_disconnected()")
        print(flush = True)

    def on_AnimalControlCommand_disconnected(self) :
        print("py::on_AnimalControlCommand_disconnected()")
        print(flush = True)

    def on_AnimalSpawnCommand_disconnected(self) :
        print("py::on_AnimalSpawnCommand_disconnected()")
        print(flush = True)

    def on_HumanControlCommand_disconnected(self) :
        print("py::on_HumanControlCommand_disconnected()")
        print(flush = True)

    def on_HumanSpawnCommand_disconnected(self) :
        print("py::on_HumanSpawnCommand_disconnected()")
        print(flush = True)

    # 콜백 함수
    def on_EnvObjStatusInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_EnvObjStatusInformation_sync()")
        print(flush = True)

    def on_ObjectControlInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_ObjectControlInformation_sync()")
        print(flush = True)

    def on_TimeStampInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_TimeStampInformation_sync()")
        print(flush = True)

    def on_TrafficLightControlInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        print("py::on_TrafficLightControlInformation_sync()")
        print(flush = True)

    # 시나리오 편집기로부터 패킷 받는 콜백 함수
    def on_ScenarioSettingInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.ScenarioSettingInfo = pin_buffer
        print("py::on_ScenarioSettingInformation_sync()")
        print(flush = True)

    def on_ScenarioFrequencyInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.ScenarioFrequencyInfo = pin_buffer
        print("py::on_ScenarioFrequencyInformation_sync()")
        print(flush = True)

    def on_ScenarioControlInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.ScenarioControlInfo = pin_buffer
        print("py::on_ScenarioControlInformation_sync()")
        print(flush = True)

    def on_ScenarioSignalInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.ScenarioSignalInfo = pin_buffer
        print("py::on_ScenarioSignalInformation_sync()")
        print(flush = True)

    def on_SystemSettingInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.SystemSetting = pin_buffer
        print("py::on_EventInformation_sync()")
        print(flush = True)

    def on_EventInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.EventInfo = pin_buffer
        print("py::on_EventInformation_sync()")
        print(flush = True)

    def on_WeatherStatusInformation_sync(self, in_sync_model, in_elapsed, in_limit, pin_buffer) :
        self.WeatherStatusInfo = pin_buffer
        print("py::on_WeatherStatusInformation_sync()")
        print(flush = True)

    # 가변 버퍼 필드를 적재할 리스트
    def __init__(self) :
        self.spawn_human_list = []
        self.spawn_animal_list = []
        self.spawn_vehicle_list = []
        self.spawn_envobj_list = []
        self.control_human_list = []
        self.control_animal_list = []
        self.control_vehicle_list = []
        self.control_envobj_list = []
        self.control_traffic_list = []

        # 부모 클래스 생성자 호출
        nerv.proxy_coretec_scenario.__init__(self)

    # spawn human 데이터 적재
    def spawn_human_append(self, human_info) :
        self.spawn_human_list.append(human_info)
    
    # spawn animal 데이터 적재
    def spawn_animal_append(self, animal_info) :
        self.spawn_animal_list.append(animal_info)

    # spawn vehicle 데이터 적재
    def spawn_vehicle_append(self, vehicle_info) :
        self.spawn_vehicle_list.append(vehicle_info)

    # spawn envobj 데이터 적재
    def spawn_envobj_append(self, envobj_info) :
        self.spawn_envobj_list.append(envobj_info)

    # control human 데이터 적재
    def control_human_append(self, human_info) :
        self.control_human_list.append(human_info)

    # control animal 데이터 적재
    def control_animal_append(self, animal_info) :
        self.control_animal_list.append(animal_info)

    # control vehicle 데이터 적재
    def control_vehicle_append(self, vehicle_info) :
        self.control_vehicle_list.append(vehicle_info)

    # control envobj 데이터 적재
    def control_envobj_append(self, envobj_info) :
        self.control_envobj_list.append(envobj_info)

    # control trafficlight 데이터 적재
    def control_trafficlight_append(self, traffic_info) :
        self.control_traffic_list.append(traffic_info)

    # spawn 적재된 데이터 전송
    def send_spawn_all(self) :
        
        # 가변버퍼 초기화
        Spawn_Info = self.SpawnCommand_get()
        Spawn_Info.init_dynamic_buffer()

        # human 필드 크기 할당 및 값 설정
        human_list_size = len(self.spawn_human_list)
        Spawn_Info.human_spawn_alloc(human_list_size)
        
        for i in range(human_list_size) :
            human = Spawn_Info.human_spawn(i)
            human.HumanID = self.spawn_human_list[i].HumanID
            human.Location[0] = self.spawn_human_list[i].Location[0]
            human.Location[1] = self.spawn_human_list[i].Location[1]
            human.Location[2] = self.spawn_human_list[i].Location[2]
            human.Rotation[0] = self.spawn_human_list[i].Rotation[0]
            human.Rotation[1] = self.spawn_human_list[i].Rotation[1]
            human.Rotation[2] = self.spawn_human_list[i].Rotation[2]
            human.ResourceType = self.spawn_human_list[i].ResourceType
        
        # animal 필드 크기 할당 및 값 설정
        animal_list_size = len(self.spawn_animal_list)
        Spawn_Info.animal_spawn_alloc(animal_list_size)

        for i in range(animal_list_size) :
            animal = Spawn_Info.animal_spawn(i)
            animal.AnimalID = self.spawn_animal_list[i].AnimalID
            animal.Location[0] = self.spawn_animal_list[i].Location[0]
            animal.Location[1] = self.spawn_animal_list[i].Location[1]
            animal.Location[2] = self.spawn_animal_list[i].Location[2]
            animal.Rotation[0] = self.spawn_animal_list[i].Rotation[0]
            animal.Rotation[1] = self.spawn_animal_list[i].Rotation[1]
            animal.Rotation[2] = self.spawn_animal_list[i].Rotation[2]
            animal.ResourceType = self.spawn_animal_list[i].ResourceType

        # vehicle 필드 크기 할당 및 값 설정
        vehicle_list_size = len(self.spawn_vehicle_list)
        Spawn_Info.vehicle_spawn_alloc(vehicle_list_size)

        for i in range(vehicle_list_size) :
            vehicle = Spawn_Info.vehicle_spawn(i)
            vehicle.VehicleID = self.spawn_vehicle_list[i].VehicleID
            vehicle.Location[0] = self.spawn_vehicle_list[i].Location[0]
            vehicle.Location[1] = self.spawn_vehicle_list[i].Location[1]
            vehicle.Location[2] = self.spawn_vehicle_list[i].Location[2]
            vehicle.Rotation[0] = self.spawn_vehicle_list[i].Rotation[0]
            vehicle.Rotation[1] = self.spawn_vehicle_list[i].Rotation[1]
            vehicle.Rotation[2] = self.spawn_vehicle_list[i].Rotation[2]
            vehicle.ResourceType = self.spawn_vehicle_list[i].ResourceType

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

    # control 적재된 데이터 전송
    def send_control_all(self) :
        
        # 가변버퍼 초기화
        Control_Info = self.ControlInfoCommand_get()
        Control_Info.init_dynamic_buffer()

        # human 필드 크기 할당 및 값 설정
        human_list_size = len(self.control_human_list)
        Control_Info.human_objects_alloc(human_list_size)
        
        for i in range(human_list_size) :
            human = Control_Info.human_objects(i)
            human.HumanID = self.control_human_list[i].HumanID
            human.ActionType = self.control_human_list[i].ActionType
##            human.Destination[0] = self.control_human_list[i].Destination[0]
##            human.Destination[1] = self.control_human_list[i].Destination[1]
##            human.Destination[2] = self.control_human_list[i].Destination[2]
            human.Rotation[0] = self.control_human_list[i].Rotation[0]
            human.Rotation[1] = self.control_human_list[i].Rotation[1]
            human.Rotation[2] = self.control_human_list[i].Rotation[2]
         
        # animal 필드 크기 할당 및 값 설정
        animal_list_size = len(self.control_animal_list)
        Control_Info.animal_objects_alloc(animal_list_size)
        
        for i in range(animal_list_size) :
            animal = Control_Info.animal_objects(i)
            animal.AnimalID = self.control_animal_list[i].AnimalID
            animal.ActionType = self.control_animal_list[i].ActionType
##            animal.Destination[0] = self.control_animal_list[i].Destination[0]
##            animal.Destination[1] = self.control_animal_list[i].Destination[1]
##            animal.Destination[2] = self.control_animal_list[i].Destination[2]
            animal.Rotation[0] = self.control_animal_list[i].Rotation[0]
            animal.Rotation[1] = self.control_animal_list[i].Rotation[1]
            animal.Rotation[2] = self.control_animal_list[i].Rotation[2]

        # vehicle 필드 크기 할당 및 값 설정
        vehicle_list_size = len(self.control_vehicle_list)
        Control_Info.vehicle_objects_alloc(vehicle_list_size)
        for i in range(vehicle_list_size) :
        
            vehicle = Control_Info.vehicle_objects(i)
            vehicle.VehicleID = self.control_vehicle_list[i].VehicleID
            vehicle.ActionType = self.control_vehicle_list[i].ActionType
##            vehicle.Destination[0] = self.control_vehicle_list[i].Destination[0]
##            vehicle.Destination[1] = self.control_vehicle_list[i].Destination[1]
##            vehicle.Destination[2] = self.control_vehicle_list[i].Destination[2]
            vehicle.Direction[0] = self.control_vehicle_list[i].Direction[0]
            vehicle.Direction[1] = self.control_vehicle_list[i].Direction[1]
            vehicle.Direction[2] = self.control_vehicle_list[i].Direction[2]

        #  필드 크기 할당 및 값 설정
        envobj_list_size = len(self.control_envobj_list)
        Control_Info.envobj_objects_alloc(envobj_list_size)
        
        for i in range(envobj_list_size) :
            envobj = Control_Info.envobj_objects(i)
            envobj.EnvObjID = self.control_envobj_list[i].EnvObjID
            envobj.ActionType = self.control_envobj_list[i].ActionType
##            envobj.Destination[0] = self.control_envobj_list[i].Destination[0]
##            envobj.Destination[1] = self.control_envobj_list[i].Destination[1]
##            envobj.Destination[2] = self.control_envobj_list[i].Destination[2]
            envobj.Rotation[0] = self.control_envobj_list[i].Rotation[0]
            envobj.Rotation[1] = self.control_envobj_list[i].Rotation[1]
            envobj.Rotation[2] = self.control_envobj_list[i].Rotation[2]

        # @@@ traffic_light 추가
        traffic_list_size = len(self.control_traffic_list)
        Control_Info.traffic_light_objects_alloc(traffic_list_size)

        for i in range(traffic_list_size) :
            traffic = Control_Info.traffic_light_objects(i)
            traffic.TrafficLightID = self.control_traffic_list[i].TrafficLightID
            traffic.TrafficLightState =  self.control_traffic_list[i].TrafficLightState

        # 작성한 가변필드가 있는 구조데이터를 post하여 실제 전송이 발생하도록 합니다.
        self.ControlInfo_post(Control_Info)

        self.control_animal_list.clear()
        self.control_human_list.clear()
        self.control_vehicle_list.clear()
        self.control_envobj_list.clear()
        self.control_traffic_list.clear()

def OnServerConnect() :
    global proxy_obj
    global Total_Npc_Count
    global Total_Human_ID_Count
    global Total_Animal_ID_Count
    global Total_Vehicle_ID_Count
    
    # nerv 별도 스레드 설정
    nerv_thread = threading.Thread(target=nerv_init)    
    nerv_thread.daemon = True
    nerv_thread.start()
    
    proxy_obj = proxy_AI()
    stub_obj_id = 1
    print("nerv.const.c_AI_port : %d\n" %nerv.const.c_AI_port)
    proxy_obj.create(nerv.const.c_AI_port, nerv.inet_addr("127.0.0.1"), stub_obj_id, 0)    

    # Spawn_Info = nerv.SpawnInfo()
    # Control_Info = nerv.ControlInfo()

    Total_Npc_Count = 0
    Total_Human_ID_Count = 0
    Total_Animal_ID_Count = 0
    Total_Vehicle_ID_Count = 0

def signal_handler(sig, frame):
    print("signal_handler() called")
    print(flush = True)
    nerv.finalize()
    sys.exit(0)

def nerv_init() :
    nerv.initialize()
    print("nerv_init() start\n")    
    while True :
        nerv.dispatch_msg(0)
        time.sleep(0.001)
    nerv.finalize()
    print("nerv_init() end")

def SpawnAllNpc(HumanNum, AnimalNum, VehicleNum) :
    global Total_Npc_Count
    global Total_Human_ID_Count
    global Total_Animal_ID_Count
    global Total_Vehicle_ID_Count

    # 사람
    HumanCount = 0
    while HumanCount < HumanNum :
        human_spawn_info = nerv.HumanSpawnInfo()
        human_spawn_info.HumanID = "%d" %Total_Human_ID_Count
        Total_Human_ID_Count = Total_Human_ID_Count + 1
        human_spawn_info.Location[0] = 7000 + (Total_Npc_Count % 5) * 500
        human_spawn_info.Location[1] = 7000 + (Total_Npc_Count / 10) * 1000 + (Total_Npc_Count * 100)
        human_spawn_info.Location[2] = 500
        human_spawn_info.Rotation[0] = 0
        human_spawn_info.Rotation[1] = 1
        human_spawn_info.Rotation[2] = 0
        human_spawn_info.ResourceType = HumanCount % 8
        HumanCount = HumanCount + 1
        Total_Npc_Count = Total_Npc_Count + 1

        proxy_obj.spawn_human_append(human_spawn_info)

    # 동물
    AnimalCount = 0
    while AnimalCount < AnimalNum :
        animal_spawn_info = nerv.AnimalSpawnInfo()
        animal_spawn_info.AnimalID = "%d" %Total_Animal_ID_Count
        Total_Animal_ID_Count = Total_Animal_ID_Count + 1
        animal_spawn_info.Location[0] = 7000 + (Total_Npc_Count % 5) * 500
        animal_spawn_info.Location[1] = 7000 + (Total_Npc_Count / 10) * 1000 + (Total_Npc_Count * 100)
        animal_spawn_info.Location[2] = 500
        animal_spawn_info.Rotation[0] = 0
        animal_spawn_info.Rotation[1] = 1
        animal_spawn_info.Rotation[2] = 0
        animal_spawn_info.ResourceType = AnimalCount % 6
        AnimalCount = AnimalCount + 1
        Total_Npc_Count = Total_Npc_Count + 1

        proxy_obj.spawn_animal_append(animal_spawn_info)

    # 차량
    VehicleCount = 0
    while VehicleCount < VehicleNum :
        vehicle_spawn_info = nerv.VehicleSpawnInfo()
        vehicle_spawn_info.AnimalID = "%d" %Total_Vehicle_ID_Count
        Total_Vehicle_ID_Count = Total_Vehicle_ID_Count + 1
        vehicle_spawn_info.Location[0] = 7000 + (Total_Npc_Count % 5) * 500
        vehicle_spawn_info.Location[1] = 7000 + (Total_Npc_Count / 10) * 1000 + (Total_Npc_Count * 100)
        vehicle_spawn_info.Location[2] = 500
        vehicle_spawn_info.Rotation[0] = 0
        vehicle_spawn_info.Rotation[1] = 1
        vehicle_spawn_info.Rotation[2] = 0
        vehicle_spawn_info.ResourceType = VehicleCount % 5
        VehicleCount = VehicleCount + 1
        Total_Npc_Count = Total_Npc_Count + 1

        proxy_obj.spawn_vehicle_append(vehicle_spawn_info)

def ControlAllNpc(HumanCommand, AimalCommand, VehicleCommand, Rotation_X, Rotation_Y) :
    # 사람
    HumanCount = 0
    while HumanCount < Total_Human_ID_Count :
        human_control_info = nerv.HumanControlInfo()
        human_control_info.HumanID = "%d" %HumanCount
        human_control_info.ActionType = HumanCommand
##        human_control_info.Destination[0] = 27800 + (HumanCount % 5) * 500
##        human_control_info.Destination[1] = -1900 + (HumanCount / 10) * 1000 + (HumanCount * 100)
##        human_control_info.Destination[2] = 500
        human_control_info.Rotation[0] = Rotation_X
        human_control_info.Rotation[1] = Rotation_Y
        human_control_info.Rotation[2] = 0
        HumanCount = HumanCount + 1

        proxy_obj.control_human_append(human_control_info)

    # 동물
    AnimalCount = 0
    while AnimalCount < Total_Animal_ID_Count :
        animal_control_info = nerv.AnimalControlInfo()
        animal_control_info.AnimalID = "%d" %AnimalCount
        animal_control_info.ActionType = AimalCommand
##        animal_control_info.Destination[0] = 27800 + ((Total_Human_ID_Count + AnimalCount) % 5) * 500
##        animal_control_info.Destination[1] = -1900 + ((Total_Human_ID_Count + AnimalCount) / 10) * 1000 + ((Total_Human_ID_Count + AnimalCount) * 100)
##        animal_control_info.Destination[2] = 500
        animal_control_info.Rotation[0] = Rotation_X
        animal_control_info.Rotation[1] = Rotation_Y
        animal_control_info.Rotation[2] = 0
        AnimalCount = AnimalCount + 1

        proxy_obj.control_animal_append(animal_control_info)

    # 차량
    VehicleCount = 0
    while VehicleCount < Total_Vehicle_ID_Count :
        vehicle_control_info = nerv.VehicleControlInfo()
        vehicle_control_info.VehicleID = "%d" %VehicleCount
        vehicle_control_info.ActionType = VehicleCommand
##        vehicle_control_info.Destination[0] = 27800 + ((Total_Human_ID_Count + Total_Animal_ID_Count + VehicleCount) % 5) * 500
##        vehicle_control_info.Destination[1] = -1900 + ((Total_Human_ID_Count + Total_Animal_ID_Count + VehicleCount) / 10) * 1000 + ((Total_Human_ID_Count + Total_Animal_ID_Count + VehicleCount) * 100)
##        vehicle_control_info.Destination[2] = 500
        vehicle_control_info.Direction[0] = Rotation_X
        vehicle_control_info.Direction[1] = Rotation_Y
        vehicle_control_info.Direction[2] = 0
        VehicleCount = VehicleCount + 1

        proxy_obj.control_vehicle_append(vehicle_control_info)

def AllAgentsInfomation() :
    string_info = nerv.StringInfo()
    string_info.data = "AllAgentsInformation"
    proxy_obj.StringInfoCommand_write(string_info)

def spawntest(num) :
    SpawnAllNpc(num, num, num)
    proxy_obj.send_spawn_all()

def controltest() :
    direction = 0
    while True :
        if ((direction % 4) == 0) :
            ControlAllNpc(1, 1, 1, 0, 1)
        elif ((direction % 4) == 1) :
            ControlAllNpc(1, 1, 1, 1, 0)
        elif ((direction % 4) == 2) :
            ControlAllNpc(1, 1, 1, 0, -1)
        elif ((direction % 4) == 3) :
            ControlAllNpc(1, 1, 1, -1, 0)
        proxy_obj.send_control_all()
        direction = direction + 1
        time.sleep(1)
        
# main() 함수
if __name__ == '__main__' :
    signal.signal(signal.SIGINT, signal_handler)
    OnServerConnect()

def example() :
    # @@@ DeleteObjectInfo 사용법
    delete_obj_info = nerv.DeleteObjectInfo()
    delete_obj_info.DeleteObjectID = "123"
    delete_obj_info.DeleteObjectType = 1

    # @@@ DeactiveEventInfo 사용법 
    deactive_event_info = nerv.DeactiveEventInfo()
    deactive_event_info.set_DeactiveEventList(0, "event1")
    deactive_event_info.set_DeactiveEventList(1, "event2"deactive_event_info.set_DeactiveEventList(2, "event3")
    deactive_event_info.DeactiveEventCount = 3

    proxy_obj.DeactivEventInfo_write(deactive_event_info)

