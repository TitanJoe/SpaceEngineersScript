public void Main(){
//"Get blocks" functions.
//Includes: BaseAssembler, BaseRefinery, BaseDisplay, BaseBatteryTop, BaseBatteryBot.
    IMyAssembler BaseAssembler = (IMyAssembler)GridTerminalSystem.GetBlockWithName("BaseAssembler");
    IMyRefinery BaseRefinery = (IMyRefinery)GridTerminalSystem.GetBlockWithName("BaseRefinery");
    IMyTextPanel BaseDisplay = (IMyTextPanel)GridTerminalSystem.GetBlockWithName("BaseDisplay");
    IMyBatteryBlock BaseBatteryTop = (IMyBatteryBlock)GridTerminalSystem.GetBlockWithName("BaseBatteryTop");
    IMyBatteryBlock BaseBatteryBot = (IMyBatteryBlock)GridTerminalSystem.GetBlockWithName("BaseBatteryBot");

//"Get BaseAssembler stats" functions.
//Includes: Enabled? IsProdcing?
    bool  BaseAssemblerEnabled = BaseAssembler.Enabled;
    bool  BaseAssemblerIsProducing = BaseAssembler.IsProducing;

//"Get BaseRefinery stats" functions.
//Includes: Enabled? IsProdcing?
    bool  BaseRefineryEnabled = BaseRefinery.Enabled;
    bool  BaseRefineryIsProducing = BaseRefinery.IsProducing;

//"Get BaseBatteryTop stats" functions.
//Includes: CurrentStoredPower? IsCharging?
    float BaseBatteryTopCurrentStoredPower = BaseBatteryTop.CurrentStoredPower;
    bool BaseBatteryTopIsCharging = BaseBatteryTop.IsCharging;

//"Get BaseBatteryBot stats" functions.
//Includes: CurrentStoredPower? IsCharging?
    float BaseBatteryBotCurrentStoredPower = BaseBatteryBot.CurrentStoredPower;
    bool BaseBatteryBotIsCharging = BaseBatteryBot.IsCharging;

//"Get BaseBattery total CurrentStoredPower" function
    float BaseBatteriesTotalPower =  BaseBatteryTopCurrentStoredPower + BaseBatteryBotCurrentStoredPower;

//"Get BaseBatteryPercent" function
    float BaseBatteriesPercentFloat = BaseBatteriesTotalPower / 6 *100;
    int BaseBatteriesPercent = (int)BaseBatteriesPercentFloat;

//"Get BaseBatteryChargeState" function
    //It is hidden by default but is shown if BaseBatteries drops below 99%
    string BaseBatteriesChargeState = "";
    if (BaseBatteriesPercent < 99) {
        BaseBatteriesChargeState =
            "\nBaseBatteryTop is "
            //Coverts "bool" to "string"
            +(BaseBatteryTopIsCharging?"charging":"discharging")
            +"\nBaseBatteryBot is "
            //Coverts "bool" to "string"
            +(BaseBatteryTopIsCharging?"charging":"discharging");}

//"Display them on BaseDisplay" function.
// Also converts th booleans to words, see in brackets.
//Includes: BaseAssembler line, BaseRefinery line.
    BaseDisplay.WriteText(
    //BaseAssembler line
        "BaseAssembler is "
        +(BaseAssemblerEnabled?"on":"off")
        +" and is "
        +(BaseAssemblerIsProducing?"producing":"not producing")
        +"\n"
    //BaseRefinery line.
        +"BaseRefinery is "
        +(BaseRefineryEnabled?"on":"off")
        +" and is "
        +(BaseRefineryIsProducing?"producing":"not producing")
        +"\n"
    //BaseBatteries line.
        +"BaseBatteries are "
        +BaseBatteriesPercent
        +"%"
        +BaseBatteriesChargeState
        +"");
}