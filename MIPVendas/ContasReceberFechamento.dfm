object FContasReceberFechamento: TFContasReceberFechamento
  Left = 0
  Top = 0
  Caption = 'Realizar Fechamento'
  ClientHeight = 660
  ClientWidth = 1146
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
  object Label1: TLabel
    Left = 599
    Top = 128
    Width = 525
    Height = 18
    Caption = 
      '---------------------------------------TABELA DE FECHAMENTOS----' +
      '------------------------------'
  end
  object PanelTopo: TPanel
    Left = 0
    Top = 0
    Width = 1146
    Height = 113
    Align = alTop
    Color = 5395281
    ParentBackground = False
    TabOrder = 0
    object LabelTitulo: TLabel
      Left = 40
      Top = 20
      Width = 478
      Height = 40
      Caption = 'REALIZAR FECHAMENTO DE CONTA'
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
  object StringGrid1: TStringGrid
    Left = 599
    Top = 152
    Width = 526
    Height = 481
    TabOrder = 1
    OnSelectCell = StringGrid1SelectCell
  end
  object Panel1: TPanel
    Left = 29
    Top = 128
    Width = 526
    Height = 505
    Color = clWhite
    ParentBackground = False
    TabOrder = 2
    object Label2: TLabel
      Left = 21
      Top = 24
      Width = 180
      Height = 18
      Caption = 'VALOR DO FECHAMENTO (R$)'
    end
    object Label6: TLabel
      Left = 21
      Top = 311
      Width = 133
      Height = 18
      Caption = 'VALOR RESTANTE (R$)'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6974058
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object Label3: TLabel
      Left = 21
      Top = 230
      Width = 92
      Height = 18
      Caption = 'DESCONTO (%)'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6974058
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object Label4: TLabel
      Left = 157
      Top = 230
      Width = 96
      Height = 18
      Caption = 'DESCONTO (R$)'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6974058
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object Label5: TLabel
      Left = 297
      Top = 230
      Width = 107
      Height = 18
      Caption = 'VALOR TOTAL(R$)'
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6974058
      Font.Height = 18
      Font.Name = 'Calibri'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object LabelCliente: TLabel
      Left = 21
      Top = 189
      Width = 62
      Height = 20
      Caption = 'CLIENTE: '
      Color = clGray
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clDefault
      Font.Height = 20
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object Label8: TLabel
      Left = 21
      Top = 141
      Width = 138
      Height = 18
      Caption = 'DATA DE VENCIMENTO'
    end
    object EditValorFechamento: TEdit
      Left = 21
      Top = 48
      Width = 481
      Height = 63
      Color = 5395281
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 3198613
      Font.Height = 55
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object ButtonCancelar: TButton
      Left = 361
      Top = 412
      Width = 141
      Height = 80
      Caption = 'CANCELAR'
      TabOrder = 1
      OnClick = ButtonCancelarClick
    end
    object ButtonDinheiro: TButton
      Left = 21
      Top = 412
      Width = 145
      Height = 37
      Caption = 'DINHEIRO (F1)'
      TabOrder = 2
      OnClick = ButtonDinheiroClick
    end
    object ButtonCartao: TButton
      Left = 191
      Top = 412
      Width = 145
      Height = 37
      Caption = 'CART'#195'O (F2)'
      TabOrder = 3
      OnClick = ButtonCartaoClick
    end
    object ButtonCheque: TButton
      Left = 21
      Top = 455
      Width = 145
      Height = 37
      Caption = 'CHEQUE (F3)'
      TabOrder = 4
      OnClick = ButtonChequeClick
    end
    object ButtonBoleto: TButton
      Left = 191
      Top = 455
      Width = 145
      Height = 37
      Caption = 'BOLETO (F4)'
      TabOrder = 5
      OnClick = ButtonBoletoClick
    end
    object EditValorRestante: TEdit
      Left = 21
      Top = 335
      Width = 481
      Height = 63
      Color = 5395281
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 3198613
      Font.Height = 55
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
    end
    object EditDescontoP: TEdit
      Left = 21
      Top = 254
      Width = 122
      Height = 48
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnExit = EditDescontoPExit
      OnKeyPress = EditDescontoPKeyPress
    end
    object EditDescontoD: TEdit
      Left = 149
      Top = 254
      Width = 122
      Height = 48
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnExit = EditDescontoDExit
      OnKeyPress = EditDescontoDKeyPress
    end
    object EditValorTotal: TEdit
      Left = 297
      Top = 254
      Width = 205
      Height = 48
      Color = 15790835
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 40
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 9
    end
    object data_vencimento: TDateTimePicker
      Left = 176
      Top = 132
      Width = 326
      Height = 34
      Date = 42424.436163495370000000
      Time = 42424.436163495370000000
      TabOrder = 10
    end
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 600
    Top = 24
  end
  object ActionList1: TActionList
    Left = 664
    Top = 22
    object Del: TAction
      Caption = 'Del'
      ShortCut = 46
      OnExecute = DelExecute
    end
    object F1: TAction
      Caption = 'F1'
      ShortCut = 112
      OnExecute = F1Execute
    end
    object F2: TAction
      Caption = 'F2'
      ShortCut = 113
      OnExecute = F2Execute
    end
    object F3: TAction
      Caption = 'F3'
      ShortCut = 114
      OnExecute = F3Execute
    end
    object F4: TAction
      Caption = 'F4'
      ShortCut = 115
      OnExecute = F4Execute
    end
  end
end
