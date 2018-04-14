object Form1: TForm1
  Left = 503
  Top = 290
  Width = 603
  Height = 501
  Caption = #1054#1073#1088#1072#1090#1085#1072#1103' '#1087#1086#1083#1100#1089#1082#1072#1103' '#1079#1072#1087#1080#1089#1100
  Color = clInactiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object StringGrid1: TStringGrid
    Left = 10
    Top = 10
    Width = 168
    Height = 444
    ColCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    OnKeyPress = StringGrid1KeyPress
  end
  object Edit1: TEdit
    Left = 187
    Top = 10
    Width = 139
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 187
    Top = 39
    Width = 139
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
    OnKeyPress = Edit2KeyPress
  end
  object Button1: TButton
    Left = 335
    Top = 10
    Width = 129
    Height = 31
    Caption = #1055#1077#1088#1077#1074#1077#1089#1090#1080
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 335
    Top = 39
    Width = 129
    Height = 31
    Caption = #1055#1086#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 4
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 187
    Top = 69
    Width = 139
    Height = 21
    TabOrder = 5
    Text = 'Edit3'
  end
  object Memo1: TMemo
    Left = 187
    Top = 98
    Width = 385
    Height = 356
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 6
  end
  object Button3: TButton
    Left = 335
    Top = 69
    Width = 129
    Height = 31
    Caption = #1040#1074#1090#1086#1079#1072#1087#1086#1083#1085#1077#1085#1080#1077
    TabOrder = 7
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 482
    Top = 10
    Width = 93
    Height = 31
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 482
    Top = 39
    Width = 93
    Height = 31
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 9
    OnClick = Button5Click
  end
end
