object Form1: TForm1
  Left = 264
  Top = 225
  Width = 1041
  Height = 439
  Caption = #1040#1087#1087#1088#1086#1082#1089#1080#1084#1072#1094#1080#1103' '#1092#1091#1085#1082#1094#1080#1081
  Color = clSkyBlue
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
    Left = 552
    Top = 16
    Width = 47
    Height = 13
    Caption = #1053#1072#1095#1072#1083#1086' '#1040
  end
  object Label2: TLabel
    Left = 552
    Top = 40
    Width = 41
    Height = 13
    Caption = #1050#1086#1085#1077#1094' B'
  end
  object Label3: TLabel
    Left = 552
    Top = 64
    Width = 49
    Height = 13
    Caption = #1047#1072#1076#1072#1085#1086' M'
  end
  object Label4: TLabel
    Left = 552
    Top = 88
    Width = 42
    Height = 13
    Caption = #1053#1072#1081#1090#1080' N'
  end
  object Chart1: TChart
    Left = 8
    Top = 8
    Width = 537
    Height = 257
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082#1080' '#1092#1091#1085#1082#1094#1080#1081)
    TabOrder = 0
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Title = 'F(x)'
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clGreen
      Title = #1051#1072#1075#1088#1072#1085#1076#1078#1072
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series3: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clYellow
      Title = #1051#1080#1085#1077#1081#1085#1072#1103
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series4: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
      Title = #1050#1074#1072#1076#1088#1072#1090#1080#1095#1085#1072#1103
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Edit1: TEdit
    Left = 608
    Top = 8
    Width = 97
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 608
    Top = 32
    Width = 97
    Height = 21
    TabOrder = 2
    Text = 'Edit2'
    OnKeyPress = Edit2KeyPress
  end
  object Button1: TButton
    Left = 552
    Top = 216
    Width = 75
    Height = 49
    Caption = #1042#1099#1095#1080#1089#1083#1080#1090#1100
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 608
    Top = 56
    Width = 97
    Height = 21
    TabOrder = 4
    Text = 'Edit3'
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 608
    Top = 80
    Width = 97
    Height = 21
    TabOrder = 5
    Text = 'Edit4'
    OnKeyPress = Edit4KeyPress
  end
  object Memo1: TMemo
    Left = 712
    Top = 8
    Width = 305
    Height = 257
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 6
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 272
    Width = 1009
    Height = 120
    DefaultColWidth = 85
    TabOrder = 7
  end
  object RadioGroup1: TRadioGroup
    Left = 552
    Top = 104
    Width = 153
    Height = 105
    Caption = #1060#1091#1085#1082#1094#1080#1103
    Items.Strings = (
      'x^3-5*x^2'
      'x*x-10*(sin(x))^2'
      'ln(x)-5*cos(x)')
    TabOrder = 8
    OnClick = RadioGroup1Click
  end
  object Button2: TButton
    Left = 632
    Top = 216
    Width = 75
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 9
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 632
    Top = 240
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 10
    OnClick = Button3Click
  end
end
