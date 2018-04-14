object Form1: TForm1
  Left = 76
  Top = 258
  Width = 1132
  Height = 465
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
    Left = 16
    Top = 24
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label2: TLabel
    Left = 16
    Top = 64
    Width = 7
    Height = 13
    Caption = 'B'
  end
  object Label3: TLabel
    Left = 16
    Top = 96
    Width = 21
    Height = 13
    Caption = 'EPS'
  end
  object Label4: TLabel
    Left = 16
    Top = 128
    Width = 8
    Height = 13
    Caption = 'H'
  end
  object Edit1: TEdit
    Left = 40
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
    OnKeyPress = Edit1KeyPress
  end
  object Edit2: TEdit
    Left = 40
    Top = 56
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Edit2'
    OnKeyPress = Edit2KeyPress
  end
  object Edit3: TEdit
    Left = 40
    Top = 88
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit3'
    OnKeyPress = Edit3KeyPress
  end
  object Edit4: TEdit
    Left = 40
    Top = 120
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit4'
    OnKeyPress = Edit4KeyPress
  end
  object Memo1: TMemo
    Left = 16
    Top = 224
    Width = 433
    Height = 193
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 4
  end
  object Button1: TButton
    Left = 16
    Top = 152
    Width = 193
    Height = 57
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 5
    OnClick = Button1Click
  end
  object Chart1: TChart
    Left = 464
    Top = 32
    Width = 649
    Height = 385
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    Legend.Visible = False
    View3D = False
    TabOrder = 6
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
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
  object Button2: TButton
    Left = 224
    Top = 152
    Width = 113
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 7
    OnClick = Button2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 168
    Top = 24
    Width = 113
    Height = 113
    Caption = #1060#1091#1085#1082#1094#1080#1103':'
    Items.Strings = (
      'x-5*sinx*sinx-5'
      'x^3+10*x^2-50'
      'sinx*sinx-3*cosx')
    TabOrder = 8
    OnClick = RadioGroup1Click
  end
  object RadioGroup2: TRadioGroup
    Left = 288
    Top = 24
    Width = 169
    Height = 113
    Caption = #1052#1077#1090#1086#1076#1099':'
    Items.Strings = (
      #1052#1077#1090#1086#1076' '#1042#1077#1075#1089#1090#1077#1081#1085#1072
      #1052#1077#1090#1086#1076' '#1076#1077#1083#1077#1085#1080#1103' '#1087#1086#1087#1086#1083#1072#1084)
    TabOrder = 9
  end
  object Button3: TButton
    Left = 224
    Top = 184
    Width = 113
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 10
    OnClick = Button3Click
  end
end
