object FVendasCpf: TFVendasCpf
  Left = 0
  Top = 0
  Caption = 'Informe o CPF do cliente'
  ClientHeight = 309
  ClientWidth = 562
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object PanelTopo: TPanel
    Left = 0
    Top = 0
    Width = 562
    Height = 113
    Align = alTop
    Color = 5395281
    ParentBackground = False
    TabOrder = 0
    ExplicitWidth = 566
    object LabelTitulo: TLabel
      Left = 40
      Top = 20
      Width = 385
      Height = 40
      Caption = 'INFORME O CPF DO CLIENTE'
      Color = 432001
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 3198613
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object Label7: TLabel
      Left = 40
      Top = 66
      Width = 297
      Height = 20
      Caption = 'ELETROBIDU COMERCIAL ELETRICA LTDA ME'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15790835
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
  end
  object EditCpf: TEdit
    Left = 48
    Top = 161
    Width = 481
    Height = 63
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 3198613
    Font.Height = 55
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object ButtonCancelar: TButton
    Left = 120
    Top = 254
    Width = 145
    Height = 37
    Caption = 'CANCELAR'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
  object ButtonSalvar: TButton
    Left = 274
    Top = 254
    Width = 145
    Height = 37
    Caption = 'SALVAR (ENTER)'
    Default = True
    TabOrder = 3
    OnClick = ButtonSalvarClick
  end
end
