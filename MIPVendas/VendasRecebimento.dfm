object FVendasRecebimento: TFVendasRecebimento
  Left = 0
  Top = 0
  Caption = 'Caixa Receber'
  ClientHeight = 508
  ClientWidth = 566
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
  object LabelValorCliente: TLabel
    Left = 48
    Top = 241
    Width = 207
    Height = 18
    Caption = 'VALOR RECEBIDO DO CLIENTE (R$)'
  end
  object Label2: TLabel
    Left = 48
    Top = 137
    Width = 137
    Height = 18
    Caption = 'VALOR A RECEBER (R$)'
  end
  object LabelTroco: TLabel
    Left = 48
    Top = 334
    Width = 71
    Height = 18
    Caption = 'TROCO (R$)'
  end
  object PanelTopo: TPanel
    Left = 0
    Top = 0
    Width = 566
    Height = 113
    Align = alTop
    Color = 5395281
    ParentBackground = False
    TabOrder = 0
    object LabelTitulo: TLabel
      Left = 40
      Top = 20
      Width = 379
      Height = 40
      Caption = 'CAIXA RECEBER (DINHEIRO)'
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
  object EditValorRestante: TEdit
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
    Left = 110
    Top = 455
    Width = 145
    Height = 37
    Caption = 'CANCELAR'
    TabOrder = 2
    OnClick = ButtonCancelarClick
  end
  object ButtonReceber: TButton
    Left = 282
    Top = 455
    Width = 145
    Height = 37
    Caption = 'RECEBER (ENTER)'
    Default = True
    TabOrder = 3
    OnClick = ButtonReceberClick
  end
  object EditTroco: TEdit
    Left = 48
    Top = 361
    Width = 481
    Height = 63
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 3198613
    Font.Height = 55
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
  end
  object EditValorCliente: TEdit
    Left = 48
    Top = 265
    Width = 481
    Height = 63
    Color = 5395281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 3198613
    Font.Height = 55
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnKeyDown = EditValorClienteKeyDown
    OnKeyPress = EditValorClienteKeyPress
    OnKeyUp = EditValorClienteKeyUp
  end
end
