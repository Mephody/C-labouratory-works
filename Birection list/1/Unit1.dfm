object Form1: TForm1
  Left = 293
  Top = 219
  Width = 928
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 48
    Width = 83
    Height = 13
    Caption = #1042#1093#1086#1076#1085#1086#1081' '#1084#1072#1089#1089#1080#1074
  end
  object Label2: TLabel
    Left = 8
    Top = 80
    Width = 91
    Height = 13
    Caption = #1042#1099#1093#1086#1076#1085#1086#1081' '#1084#1072#1089#1089#1080#1074
  end
  object Label3: TLabel
    Left = 8
    Top = 112
    Width = 109
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1086#1083#1073#1094#1086#1074
  end
  object Edit1: TEdit
    Left = 8
    Top = 136
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object Memo1: TMemo
    Left = 600
    Top = 112
    Width = 305
    Height = 273
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object Button4: TButton
    Left = 8
    Top = 168
    Width = 121
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1074#1089#1105
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 296
    Top = 112
    Width = 83
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 3
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 144
    Top = 152
    Width = 233
    Height = 73
    Caption = #1048#1085#1076#1080#1074#1080#1076#1091#1072#1083#1100#1085#1086#1077' '#1079#1072#1076#1072#1085#1080#1077
    TabOrder = 4
    OnClick = Button6Click
  end
  object StringGrid1: TStringGrid
    Left = 104
    Top = 16
    Width = 793
    Height = 81
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 5
    OnKeyPress = StringGrid1KeyPress
  end
  object Button1: TButton
    Left = 144
    Top = 112
    Width = 145
    Height = 25
    Caption = 'Random (-50 to 50)'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 200
    Width = 121
    Height = 25
    Caption = #1054#1095#1080#1090#1089#1090#1080#1090#1100' '#1089#1087#1080#1089#1082#1080
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button7: TButton
    Left = 264
    Top = 232
    Width = 113
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1083#1077#1074#1072
    TabOrder = 8
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 144
    Top = 232
    Width = 113
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1087#1088#1072#1074#1072
    TabOrder = 9
    OnClick = Button8Click
  end
  object RadioGroup1: TRadioGroup
    Left = 392
    Top = 112
    Width = 193
    Height = 113
    Caption = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1087#1080#1089#1082#1086#1074
    Items.Strings = (
      #1057' '#1085#1072#1095#1072#1083#1072
      #1057' '#1082#1086#1085#1094#1072)
    TabOrder = 10
  end
end
