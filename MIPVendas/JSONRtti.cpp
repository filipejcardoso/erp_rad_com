//---------------------------------------------------------------------------

#pragma hdrstop

#include "JSONRtti.h"
#include "Produtos.h"
#include "ValueHelper.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void JSONRtti::serialize(void* instance, TRttiInstanceType *cls, TJSONObject *json)
{
	TJSONValue *jsonValue;
	TJSONValue *jsonArrayItem;
	TJSONArray *jsonArray;
	TRttiField *field;
	TRttiMethod *method;
	TValue valor;
	int instance_size;

	// Get fields RTTI
	DynamicArray<TRttiField*> fields = cls->GetFields();

	for(int k=0;k<fields.Length;k++)
	{
		field = fields[k];

		try{
			if(json->ToString().UpperCase().Trim() != "NULL")
			{
                UnicodeString sstr = json->ToString();
				jsonValue = (TJSONValue*) json->GetValue(field->Name);
				if(jsonValue != NULL)
				{
					UnicodeString str = jsonValue->ToString();
					if(!field->FieldType->IsInstance)
					{
						valor = ValueHelper::StrToValue(jsonValue->Value(), field->FieldType->ToString());
						field->SetValue(instance, valor);
					}
					else
					{
						if(field->FieldType->ToString() != "TList")
						{
							TRttiInstanceType *c = field->FieldType->AsInstance;

							TValue valor_instance = field->GetValue(instance);

							JSONRtti::serialize(valor_instance.AsObject() , c, (TJSONObject*) jsonValue);

							valor = valor_instance.AsObject();
						}
						else
						{
							TList *list;

							TValue list_instance = field->GetValue(instance);

							list = (TList*) list_instance.AsObject();

							jsonArray = (TJSONArray*)jsonValue;
							for(int i=0;i<jsonArray->Count;i++)
							{
								method = cls->GetMethod("instance_" + field->Name);
								TValue obj_instance = method->Invoke((TObject*)instance, NULL, -1);

								method = cls->GetMethod("cls_" + field->Name);
								TValue obj_cls = method->Invoke((TObject*)instance, NULL, -1);

								jsonArrayItem = jsonArray->Items[i];
								UnicodeString ssstr = jsonArrayItem->ToString();
								JSONRtti::serialize(obj_instance.AsObject(), (TRttiInstanceType*) obj_cls.AsObject(), (TJSONObject*) jsonArrayItem);

								list->Add((TObject*) obj_instance.AsObject());
							}
						}
					}
				}
			}
		}
		catch(Exception& e){
		}
	}
}
//---------------------------------------------------------------------------
TJSONObject* JSONRtti::deserialize(TObject *instance)
{
	TJSONObject *jsonObject;

	jsonObject = TJson::ObjectToJsonObject((TObject*)instance);

	return jsonObject;
}

