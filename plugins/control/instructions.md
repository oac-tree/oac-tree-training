# Control instructions

## Achieve condition

### Simple

```xml
<AchieveCondition>
    <Condition/>
    <Action/>
</AchieveCondition>
```

### With override

```xml
<AchieveConditionWithOverride>
    <Condition/>
    <Action/>
</AchieveConditionWithOverride>
```

### With timeout

```xml
<AchieveConditionWithTimeout varNames="var1" timeout="3.0">
    <Condition/>
    <Action/>
</AchieveConditionWithTimeout>
```

## Reactive sequence

```xml
<ExecuteWhile varNames="var1">
    <Action/>
    <Condition/>
</ExecuteWhile>
```

## Wait for event

```xml
<WaitForCondition varNames="var1" timeout="2.0">
    <Condition/>
</WaitForCondition>
```
