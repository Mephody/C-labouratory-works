object Form1: TForm1
  Left = 450
  Top = 261
  Width = 1172
  Height = 626
  Caption = #1044#1077#1088#1077#1074#1100#1103
  Color = clLime
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 857
    Top = 315
    Width = 156
    Height = 16
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1101#1083#1077#1084#1077#1085#1090#1086#1074':'
  end
  object Label2: TLabel
    Left = 857
    Top = 354
    Width = 40
    Height = 16
    Caption = #1050#1083#1102#1095': '
  end
  object Label3: TLabel
    Left = 10
    Top = 10
    Width = 117
    Height = 16
    Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1084#1072#1089#1089#1080#1074':'
  end
  object Label4: TLabel
    Left = 10
    Top = 158
    Width = 158
    Height = 16
    Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1085#1085#1099#1081' '#1084#1072#1089#1089#1080#1074':'
  end
  object StringGrid1: TStringGrid
    Left = 10
    Top = 30
    Width = 1106
    Height = 119
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    OnKeyPress = StringGrid1KeyPress
    OnSelectCell = StringGrid1SelectCell
    OnSetEditText = StringGrid1SetEditText
  end
  object Button1: TButton
    Left = 453
    Top = 305
    Width = 188
    Height = 31
    Caption = #1047#1072#1076#1072#1090#1100' '#1089#1083#1091#1095#1072#1081#1085#1099#1077' '#1095#1080#1089#1083#1072
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 1014
    Top = 305
    Width = 100
    Height = 24
    TabOrder = 2
    Text = 'Edit1'
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object Button2: TButton
    Left = 453
    Top = 345
    Width = 188
    Height = 30
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1076#1077#1088#1077#1074#1086
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 10
    Top = 305
    Width = 434
    Height = 267
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object Button3: TButton
    Left = 453
    Top = 384
    Width = 188
    Height = 31
    Caption = #1041#1072#1083#1072#1085#1089#1080#1088#1086#1074#1072#1085#1085#1086#1077' '#1076#1077#1088#1077#1074#1086
    TabOrder = 5
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 650
    Top = 305
    Width = 188
    Height = 31
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 6
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 650
    Top = 384
    Width = 188
    Height = 31
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1087#1072#1084#1103#1090#1100
    TabOrder = 7
    OnClick = Button5Click
  end
  object Button7: TButton
    Left = 1014
    Top = 522
    Width = 110
    Height = 50
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 8
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 453
    Top = 463
    Width = 188
    Height = 31
    Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1082#1083#1102#1095#1091
    TabOrder = 9
    OnClick = Button8Click
  end
  object Edit2: TEdit
    Left = 1014
    Top = 354
    Width = 100
    Height = 24
    TabOrder = 10
    Text = 'Edit2'
    OnKeyPress = Edit2KeyPress
  end
  object StringGrid2: TStringGrid
    Left = 10
    Top = 177
    Width = 1104
    Height = 120
    Color = clScrollBar
    RowCount = 3
    TabOrder = 11
    ColWidths = (
      64
      64
      64
      64
      64)
  end
  object Button6: TButton
    Left = 650
    Top = 423
    Width = 188
    Height = 31
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1089#1090#1088#1086#1082#1080
    TabOrder = 12
    OnClick = Button6Click
  end
  object Button9: TButton
    Left = 650
    Top = 463
    Width = 188
    Height = 31
    Caption = #1054#1095#1080#1090#1089#1090#1080#1090#1100' '#1101#1082#1088#1072#1085
    TabOrder = 13
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 453
    Top = 502
    Width = 188
    Height = 31
    Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1087#1086' '#1082#1083#1102#1095#1091
    TabOrder = 14
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 650
    Top = 345
    Width = 188
    Height = 30
    Caption = #1059#1079#1085#1072#1090#1100' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1083#1080#1089#1090#1100#1077#1074
    TabOrder = 15
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 453
    Top = 423
    Width = 188
    Height = 31
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088#1077#1090#1100' '#1076#1077#1088#1077#1074#1086
    TabOrder = 16
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 650
    Top = 502
    Width = 92
    Height = 31
    Caption = #1055#1088#1080#1084#1077#1088' 1'
    TabOrder = 17
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 748
    Top = 502
    Width = 93
    Height = 31
    Caption = #1055#1088#1080#1084#1077#1088' 2'
    TabOrder = 18
    OnClick = Button14Click
  end
end
