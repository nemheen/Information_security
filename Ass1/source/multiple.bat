@echo off
:: Sets the label value CLASS for repeated execution.
:CLASS         
:: Execute folder1~5 folders
md folder1    
md folder2    
md folder3    
md folder4    
md folder5    
:: Execute folder1~5 folders
start folder1   
start folder2   
start folder3   
start folder4   
start folder5   
:: Go to the CLASS label and repeat the folder creation and open operation.
goto CLASS