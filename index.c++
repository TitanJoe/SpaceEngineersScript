public void Main(){
//"Get blocks" functions.
    //Includes: BaseAssembler, BaseRefinery, BaseDisplay, BaseBatteryTop, BaseBatteryBot.
    IMyAssembler BaseAssembler = (IMyAssembler)GridTerminalSystem.GetBlockWithName("BaseAssembler");
    IMyRefinery BaseRefinery = (IMyRefinery)GridTerminalSystem.GetBlockWithName("BaseRefinery");
    IMyTextPanel BaseDisplay = (IMyTextPanel)GridTerminalSystem.GetBlockWithName("BaseDisplay");
    IMyBatteryBlock BaseBatteryTop = (IMyBatteryBlock)GridTerminalSystem.GetBlockWithName("BaseBatteryTop");
    IMyBatteryBlock BaseBatteryBot = (IMyBatteryBlock)GridTerminalSystem.GetBlockWithName("BaseBatteryBot");

//Get BaseAssembler stats.
    //Includes: Enabled? IsProdcing?
    bool  BaseAssemblerEnabled = BaseAssembler.Enabled;
    bool  BaseAssemblerIsProducing = BaseAssembler.IsProducing;

//Get BaseRefinery stats.
    //Includes: Enabled? IsProdcing?
    bool  BaseRefineryEnabled = BaseRefinery.Enabled;
    bool  BaseRefineryIsProducing = BaseRefinery.IsProducing;

//Get BaseBatteryTop stats.
    //Includes: CurrentStoredPower? IsCharging?
    float BaseBatteryTopCurrentStoredPower = BaseBatteryTop.CurrentStoredPower;
    bool BaseBatteryTopIsCharging = BaseBatteryTop.IsCharging;

//Get BaseBatteryBot stats.
    //Includes: CurrentStoredPower? IsCharging?
    float BaseBatteryBotCurrentStoredPower = BaseBatteryBot.CurrentStoredPower;
    bool BaseBatteryBotIsCharging = BaseBatteryBot.IsCharging;

//"Get BaseBatteries MaximumStoredPower"
    //Number of batteries
    int BaseBatteriesNumber = 2;
    //Caculate MaximumStoredPower of BaseBatteriesNumber
    float BaseBatteriesMaximumPower = BaseBatteriesNumber *3;

//Get BaseBatteries CurrentStoredPower
    //Returns a float betweeen 0 and BaseBatteriesMaximumPower
    float BaseBatteriesCurrentPower =  BaseBatteryTopCurrentStoredPower + BaseBatteryBotCurrentStoredPower;

//Get BaseBatteries CurrentStoredPower as a percentage
    //Returns an integer between 0 and 100
    //Divide BaseBatteriesCurrentPower by BaseBatteriesMaximumPower to get a percent.
    float BaseBatteriesPercentFloat = BaseBatteriesCurrentPower / BaseBatteriesMaximumPower;
    //Move the Decimal point 2 places to get a integer between 0 and 100
    float BaseBatteriesPercentMovedDecPoint = BaseBatteriesPercentFloat * 100;
    //Convert BaseBatteriesPercentMovedDecPoint to an integer
    int BaseBatteriesPercent = (int)BaseBatteriesPercentMovedDecPoint;

//Get BaseBatteryChargeState
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
//Includes: BaseAssembler line, BaseRefinery line, BaseBatteries line.
    BaseDisplay.WriteText(
    //BaseAssembler line
        "BaseAssembler is "
        //Converts "bool" to "string"
        +(BaseAssemblerEnabled?"on":"off")
        +" and is "
        //Converts "bool" to "string"
        +(BaseAssemblerIsProducing?"producing":"not producing")
        +"\n"
    //BaseRefinery line.
        +"BaseRefinery is "
        //Converts "bool" to "string"
        +(BaseRefineryEnabled?"on":"off")
        +" and is "
        //Converts "bool" to "string"
        +(BaseRefineryIsProducing?"producing":"not producing")
        +"\n"
    //BaseBatteries line.
        +"BaseBatteries are "
        +BaseBatteriesPercent
        +"%"
        +BaseBatteriesChargeState
        +"");
}